#ifndef _PROTOBUFCODEC_H_
#define _PROTOBUFCODEC_H_

#include "RpcMessage.pb.h"

#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

#include <muduo/net/TcpConnection.h>

namespace maxiaoda
{
typedef boost::shared_ptr< ::muduo::net::TcpConnection> TcpConnectionPtr;
typedef boost::shared_ptr<google::protobuf::Message> MessagePtr;
typedef boost::function< void (const ::muduo::net::TcpConnectionPtr&,
							   const RpcMessage&,
							   ::muduo::Timestamp)> ProtobufMessageCallback;

//	encoder and decoder.
//	simply add a int32_t header for datalength.
//	design for protobuf only.
class ProtobufCodec : public boost::noncopyable
{
public:
	ProtobufCodec(const ProtobufMessageCallback&);

	void send(const ::google::protobuf::Message&,const TcpConnectionPtr&);

	void onMessage(const ::muduo::net::TcpConnectionPtr&,
				   ::muduo::net::Buffer*,
				   ::muduo::Timestamp);
private:
	const static size_t kHeader = sizeof(int32_t);
	const static size_t kMaxMessage = 1024;//changeable
	const static size_t kMinMessage = 0;           //changeable
	ProtobufMessageCallback messageCallback_;
};
}

#endif
