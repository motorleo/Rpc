#ifndef _RPCCLIENT_H_
#define _RPCCLIENT_H_

#include "RpcChannel.h"

#include <muduo/net/TcpClient.h>

namespace maxiaoda
{

//	inheritance RpcClientLite can make your code shorter.
class RpcClientLite : public boost::noncopyable
{
public:
	RpcClientLite(::muduo::net::EventLoop* loop,
				  const ::muduo::net::InetAddress& serverAddr,
				  const char* nameArg = "RpcClient");

	~RpcClientLite()
	{
		::google::protobuf::ShutdownProtobufLibrary();
	}
	void connect()
	{
		client_.connect();
	}
	void disconnect()
	{
		client_.disconnect();
	}
	void enableRetry()
	{
		client_.enableRetry();
	}

	RpcChannel* getChannel()
	{
		return channel_.get();
	}
private:
	void onConnection(const ::muduo::net::TcpConnectionPtr&);
	virtual void initCallback(const ::muduo::net::TcpConnectionPtr&) = 0;
	::muduo::net::EventLoop* loop_;
	RpcChannelPtr channel_;
	::muduo::net::TcpClient client_;
};
}



#endif
