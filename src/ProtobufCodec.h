#ifndef _PROTOBUFCODEC_H_
#define _PROTOBUFCODEC_H_

#include <muduo/net/TcpConnection.h>
#include <muduo/base/Timestamp.h>
#include <muduo/net/Buffer.h>
#include "RpcMessage.pb.h"

#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

#include <string>

namespace maxiaoda
{

using namespace muduo;
using namespace muduo::net;

typedef boost::shared_ptr< ::muduo::net::TcpConnection> TcpConnectionPtr;
typedef boost::shared_ptr<google::protobuf::Message> MessagePtr;
typedef boost::function< void (const ::muduo::net::TcpConnectionPtr&,
							   const RpcMessage&,
							   ::muduo::Timestamp)> ProtobufMessageCallback;


class ProtobufCodec : public boost::noncopyable
{


public:
	ProtobufCodec(const ProtobufMessageCallback&);

	void send(const ::google::protobuf::Message&,const TcpConnectionPtr&);

	void messageCallback(const TcpConnectionPtr&,
						 Buffer*,
						 Timestamp);

private:
	const static size_t kHeader = sizeof(int32_t);
	const static size_t kMaxMessage = 16*1024*1024;//changeable
	const static size_t kMinMessage = 0;           //changeable
	ProtobufMessageCallback messageCallback_;
};

}

#endif
