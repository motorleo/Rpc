#include "test.pb.h"

#include <muduo/net/EventLoop.h>
#include "../src/RpcServer.h"

using namespace muduo;
using namespace muduo::net;
using namespace maxiaoda;

namespace test
{
	class testServiceImpl : public testService
	{
	public:
		virtual void Echo(::google::protobuf::RpcController* controller,
				const ::test::testMessage* request,
				::test::testMessage* response,
				::google::protobuf::Closure* done)
		{
			response->set_echostring(request->echostring());
			done->Run();
		}

	};
}

int main()
{
	EventLoop loop;
	InetAddress listenAddr(9981);
	test::testServiceImpl impl;
	RpcServer server(&loop, listenAddr);
	server.registerService(&impl);
	server.start();
	loop.loop();
}
