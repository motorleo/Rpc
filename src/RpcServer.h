#ifndef _RPCSERVER_H_
#define _RPCSERVER_H_

#include <muduo/net/TcpServer.h>
namespace google
{
namespace protobuf
{
	class Service;
}
}

namespace maxiaoda
{

using namespace muduo;
using namespace muduo::net;

class RpcServer : public boost::noncopyable
{

public:
	RpcServer(EventLoop* loop,
		      const InetAddress& listenAddr,
			  const string nameArg = "RpcServer");

	~RpcServer()
	{
		::google::protobuf::ShutdownProtobufLibrary();
	}

	void registerService( ::google::protobuf::Service*);
	void start()
	{
		server_.start();
	}


private:
	void onConnection(const TcpConnectionPtr&);

	typedef std::map<std::string,::google::protobuf::Service*> ServicesMap;

	ServicesMap services_;
	TcpServer server_;
};

}
#endif
