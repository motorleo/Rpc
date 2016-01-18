#include "demo.pb.h"

#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include "../src/RpcServer.h"

using namespace muduo;
using namespace muduo::net;
using namespace maxiaoda;

namespace demo
{

	class demoServiceImpl : public demoService
	{
	public:
		virtual void Solve(::google::protobuf::RpcController* controller,
				const ::demo::demoRequest* request,
				::demo::demoResponse* response,
				::google::protobuf::Closure* done)
		{
			response->set_solved(true);
			response->set_response("1234567");
			done->Run();
		}
	};

}

int main()
{
	EventLoop loop;
	InetAddress listenAddr(9981);
	demo::demoServiceImpl impl;
	RpcServer server(&loop, listenAddr);
	server.registerService(&impl);
	server.start();
	loop.loop();
}

