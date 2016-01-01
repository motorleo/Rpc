#include "RpcChannel.h"
#include "RpcClientLite.h"

#include <boost/bind.hpp>

#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>

namespace maxiaoda
{
RpcClientLite::RpcClientLite(::muduo::net::EventLoop* loop,
							 const ::muduo::net::InetAddress& serverAddr,
							 const char* nameArg)
	:loop_(loop),channel_(new RpcChannel),client_(loop,serverAddr,nameArg)
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	//version check
	client_.setConnectionCallback(
			boost::bind(&RpcClientLite::onConnection,this,_1));
	client_.setMessageCallback(
			boost::bind(&RpcChannel::onMessage,get_pointer(channel_),_1,_2,_3));
}


void RpcClientLite::onConnection(const ::muduo::net::TcpConnectionPtr& conn)
{
	LOG_INFO << "RpcClient - " << conn->localAddress().toIpPort() << " -> "
		<< conn->peerAddress().toIpPort() << " is "
		<< (conn->connected() ? "UP" : "DOWN");
	if (conn->connected())//log
	{
		channel_->setConnection(conn);
		initCallback(conn);
	}
	else
	{
		loop_->quit();
	}
}

}
