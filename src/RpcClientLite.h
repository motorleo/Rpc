#ifndef _RPCCLIENT_H_
#define _RPCCLIENT_H_

#include <muduo/net/TcpClient.h>
#include "RpcChannel.h"

namespace maxiaoda
{
using namespace muduo;
using namespace muduo::net;

class RpcClientLite : public boost::noncopyable
{
public:
	RpcClientLite(EventLoop* loop,
				  const InetAddress& serverAddr,
				  const string nameArg = "RpcClient");

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
	void onConnection(const TcpConnectionPtr&);
	
	virtual void initCallback(const TcpConnectionPtr&) = 0;

	EventLoop* loop_;
	RpcChannelPtr channel_;
	TcpClient client_;

};

}



#endif
