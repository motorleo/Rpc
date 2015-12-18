#include <muduo/net/TcpConnection>
#include <muduo/base/Timestamp.h>
#include "RpcMessage.h"

#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

#include <string>

using namespace muduo;
using namespace muduo::net;

typedef boost::shared_ptr<TcpConnection> TcpConnectionPtr;
typedef boost::shared_ptr<google::protobuf::Message> MessagePtr;
typedef boost::function< void (const TcpConnectionPtr&,
							   Buffer*,
							   Timestamp)> MessageCallback;
typedef boost::function< void (const TcpConnectionPtr&,
							   const MessagePtr&,
							   Timestamp)> ProtobufMessageCallback;


class ProtobufCodec : public boost::noncopyable
{
public:
	ProtobufCodec(const ProtobufMessageCallback&);

	void send(const MessagePtr&,const TcpConnectionPtr&);

	void messageCallback(const TcpConnectionPtr&,
						 Buffer*,
						 Timestamp);

private:
	const static int32_t kHeader=4;
	ProtobufMessageCallback messageCallback_;
};
