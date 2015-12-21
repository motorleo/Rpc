#include "RpcChannel.h"
#include "RpcClientLite.h"
#include <boost/bind.hpp>
#include <muduo/net/EventLoop.h>

namespace maxiaoda
{
RpcClientLite::RpcClientLite(EventLoop* loop,
							 const InetAddress& serverAddr,
							 const string nameArg)
	:loop_(loop),channel_(new RpcChannel),client_(loop,serverAddr,nameArg)
{
	client_.setConnectionCallback(
			boost::bind(&RpcClientLite::onConnection,this,_1));
	client_.setMessageCallback(
			boost::bind(&RpcChannel::messageCallback,get_pointer(channel_),_1,_2,_3));
}


void RpcClientLite::onConnection(const TcpConnectionPtr& conn)
{
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
