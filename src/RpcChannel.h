#ifndef _RPCCHANNEL_H_
#define _RPCCHANNEL_H_

#include "ProtobufCodec.h"
#include "MutexLockGuard.h"

#include <stdint.h>
#include <utility>

#include <muduo/net/TcpConnection.h>
#include <google/protobuf/service.h>


namespace maxiaoda
{

typedef std::map<std::string,::google::protobuf::Service*> ServicesMap;


class RpcChannel : public ::google::protobuf::RpcChannel
{  
public:

	RpcChannel();

	void CallMethod(const ::google::protobuf::MethodDescriptor* method,
					::google::protobuf::RpcController* controller,
					const ::google::protobuf::Message* request,
					::google::protobuf::Message* response,
					::google::protobuf::Closure* done);
	

	inline void onMessage(const ::muduo::net::TcpConnectionPtr& conn,
	 					  ::muduo::net::Buffer* buf,
						  ::muduo::Timestamp now)
	{
		codec_.onMessage(conn,buf,now);
	}


	void onRpcMessage(const ::muduo::net::TcpConnectionPtr&,
					  const RpcMessage&,
					  ::muduo::Timestamp);

	void setServices(const ServicesMap*);

	inline void setConnection(const ::muduo::net::TcpConnectionPtr& conn)
	{
		conn_ = conn;
	}

private:
	const char* errorToString(ErrorReason);
	void errorCall(const ::muduo::net::TcpConnectionPtr&,
					ErrorReason);
	void errorSend(const ::muduo::net::TcpConnectionPtr&,
					ErrorReason,
					int32_t);

	void doneCallback(::google::protobuf::Message*,
					  int32_t);

	typedef std::pair< ::google::protobuf::Message*,
					  ::google::protobuf::Closure*> ResponseDone;
	//must delete response in client
	typedef std::map<int32_t,ResponseDone> ResponseDoneMap;

	int32_t id_;
	ProtobufCodec codec_;
	::muduo::net::TcpConnectionPtr conn_;
	ResponseDoneMap responseDoneMap_;
	const ServicesMap* services_;
	MutexLock mutex_;
};

typedef boost::shared_ptr<RpcChannel> RpcChannelPtr;

}

#endif
