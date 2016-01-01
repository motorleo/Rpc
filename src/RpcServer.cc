#include "RpcChannel.h"
#include "RpcServer.h"

#include <muduo/base/Logging.h>

#include <google/protobuf/service.h>

#include <boost/bind.hpp>

namespace maxiaoda
{
RpcServer::RpcServer(::muduo::net::EventLoop* loop,
				     const ::muduo::net::InetAddress& listenAddr,
					 const char* nameArg)
	:server_(loop,listenAddr,nameArg)
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	//version check
	server_.setConnectionCallback(
			boost::bind(&RpcServer::onConnection,this,_1));
}

void RpcServer::registerService( ::google::protobuf::Service* service)
{
	services_[service->GetDescriptor()->name()] = service;
}

void RpcServer::onConnection(const ::muduo::net::TcpConnectionPtr& conn)
{
	LOG_INFO << "RpcServer - " << conn->peerAddress().toIpPort() << " -> "
		<< conn->localAddress().toIpPort() << " is "
		<< (conn->connected() ? "UP" : "DOWN");
	if (conn->connected())
	{
		RpcChannelPtr channel(new RpcChannel);
		channel->setConnection(conn);
		channel->setServices(&services_);
		conn->setMessageCallback(
				boost::bind(&RpcChannel::onMessage,get_pointer(channel),_1,_2,_3));
		conn->setContext(channel);
	}
	else
	{
		conn->setContext(RpcChannelPtr());
	}
}


}
