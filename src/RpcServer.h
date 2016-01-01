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
class RpcServer : public boost::noncopyable
{

public:
	RpcServer(::muduo::net::EventLoop* loop,
		      const ::muduo::net::InetAddress& listenAddr,
			  const char* nameArg = "RpcServer");

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
	void onConnection(const ::muduo::net::TcpConnectionPtr&);

	typedef std::map<std::string,::google::protobuf::Service*> ServicesMap;

	ServicesMap services_;
	::muduo::net::TcpServer server_;
};

}
#endif
