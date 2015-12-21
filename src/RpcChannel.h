#ifndef _RPCCHANNEL_H_
#define _RPCCHANNEL_H_

#include <muduo/net/TcpConnection.h>
#include "ProtobufCodec.h"
#include <google/protobuf/service.h>

#include <stdint.h>
#include <utility>

namespace maxiaoda
{

using namespace muduo;
using namespace muduo::net;
typedef std::map<std::string,::google::protobuf::Service*> ServicesMap;


class RpcChannel : public ::google::protobuf::RpcChannel
{  //FIXME: no error check
public:

	RpcChannel();

	void CallMethod(const ::google::protobuf::MethodDescriptor* method,
					::google::protobuf::RpcController* controller,
					const ::google::protobuf::Message* request,
					::google::protobuf::Message* response,
					::google::protobuf::Closure* done);
	

	inline void onMessage(const TcpConnectionPtr& conn,
	 					  Buffer* buf,
						  Timestamp now)
	{
		codec_.onMessage(conn,buf,now);
	}


	void onRpcMessage(const TcpConnectionPtr&,
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

	typedef std::pair< ::google::protobuf::Message*,
					  ::google::protobuf::Closure*> ResponseDone;
	//automically delete response in client
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
