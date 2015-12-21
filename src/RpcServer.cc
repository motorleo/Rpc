#include <google/protobuf/service.h>
#include "RpcChannel.h"
#include <boost/bind.hpp>
#include "RpcServer.h"


namespace maxiaoda
{
RpcServer::RpcServer(EventLoop* loop,
				     const InetAddress& listenAddr,
					 const string nameArg)
	:server_(loop,listenAddr,nameArg)
{
	server_.setConnectionCallback(
			boost::bind(&RpcServer::onConnection,this,_1));
}

void RpcServer::registerService( ::google::protobuf::Service* service)
{
	services_[service->GetDescriptor()->name()] = service;
}

void RpcServer::onConnection(const TcpConnectionPtr& conn)
{
	if (conn->connected())
	{
		RpcChannelPtr channel(new RpcChannel);
		channel->setConnection(conn);
		channel->setServices(&services_);
		conn->setMessageCallback(
				boost::bind(&RpcChannel::messageCallback,get_pointer(channel),_1,_2,_3));
		conn->setContext(channel);
	}
	else
	{
		conn->setContext(RpcChannelPtr());
	}
}


}
