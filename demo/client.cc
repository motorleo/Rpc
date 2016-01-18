#include "demo.pb.h"
#include "../src/RpcClientLite.h"
#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>

#include <stdio.h>


using namespace maxiaoda;
using namespace muduo;
using namespace muduo::net;

class demoClient : public maxiaoda::RpcClientLite
{
public:
	demoClient(EventLoop* loop,const InetAddress& addr)
		:RpcClientLite(loop,addr)	
	{
	}
private:
	virtual void initCallback(const TcpConnectionPtr& conn)
	{
		demo::demoService_Stub stub(getChannel());
		demo::demoRequest request;
		request.set_request("123456");
		demo::demoResponse* response(new demo::demoResponse);
		stub.Solve(NULL,&request,response,NewCallback(this,&demoClient::doneCallback,response));
	}

	void doneCallback(demo::demoResponse* response)
	{
		if (response)
		{
			LOG_INFO << "solved:\n" << response->DebugString();
			delete response;
		}
		disconnect();
	}

};

int main(int argc,char** argv)
{
	if (argc > 1)
	{
		EventLoop loop;
		InetAddress address(argv[1],9981);
		demoClient client(&loop,address);
		client.connect();
		loop.loop();
	}
	else
	{
		printf("Usage:<%s> <host_ip> !\n",argv[0]);	
	}
}
			
