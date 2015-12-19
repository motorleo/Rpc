#ifndef _RPCCHANNEL_H_
#define _RPCCHANNEL_H_

#include <string>
#include <muduo/net/TcpConnection.h>
#include <utility>
#include "RpcMessage.pb.h"
#include "ProtobufCodec.h"
#include <stdint.h>
#include <google/protobuf/service.h>
#include <boost/shared_ptr.hpp>

namespace maxiaoda
{

using namespace muduo;
using namespace muduo::net;
typedef std::map<std::string,::google::protobuf::Service*> ServicesMap;
typedef boost::shared_ptr<google::protobuf::Message> MessagePtr;


class RpcChannel : public ::google::protobuf::RpcChannel
{  //FIXME: no error check
public:

	RpcChannel();

	void CallMethod(const ::google::protobuf::MethodDescriptor* method,
					::google::protobuf::RpcController* controller,
					const ::google::protobuf::Message* request,
					::google::protobuf::Message* response,
					::google::protobuf::Closure* done);
	

	inline void messageCallback(const TcpConnectionPtr& conn,
						 Buffer* buf,
						 Timestamp now)
	{
		codec_.messageCallback(conn,buf,now);
	}


	void rpcMessageCallback(const TcpConnectionPtr&,
							const RpcMessage&,
							Timestamp);

	void setServices(const ServicesMap*);

	inline void setConnection(const TcpConnectionPtr& conn)
	{
		conn_ = conn;
	}

private:

	void doneCallback(::google::protobuf::Message*,
					  int32_t);

	typedef std::pair< ::google::protobuf::Message*,::google::protobuf::Closure*> ResponseDone;
	typedef std::map<int32_t,ResponseDone> ResponseDoneMap;

	int32_t id_;
	ProtobufCodec codec_;
	TcpConnectionPtr conn_;
	ResponseDoneMap responseDoneMap_;
	const ServicesMap* services_;
};

typedef boost::shared_ptr<RpcChannel> RpcChannelPtr;

}

#endif
