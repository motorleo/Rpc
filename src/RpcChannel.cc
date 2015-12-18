#include <google/protobuf/service.h>
#include "ProtobufCodec.h"

using namespace muduo;
using namespace muduo::net;
using namespace maxiaoda;

RpcChannel::RpcChannel()
	:id_(-1),codec_(boost::bind(&rpcMessageCallback,this,1_,2_,3_))
{
}

void RpcChannel::CallMethod(const ::google::protobuf::MethodDescriptor* method,
							::google::protobuf::RpcController* controller,
							const ::google::protobuf::Message* request,
							::google::protobuf::Message* response,
							::google::protobuf::Closure* done)
{
	RpcMessage message;
	message.set_type(REQUEST);
	message.set_id(++id_);//FIXME:not threadsafe
	message.set_service(method->service()->name());
	message.set_method(method->name());
	std::string str;
	request->SerializeToString(str);
	message.set_contend(str);
	
	responseDoneMap_[id_] = { response,done };//FIXME:unsafe

	codec_.send(message,conn_);
}
	

inline void RpcChannel::messageCallback(const TcpConnectionPtr& conn,
					 Buffer* buf,
					 Timestamp now)
{
	codec_.messageCallback(conn,buf,now);
}


void RpcChannel::rpcMessageCallback(const TcpConnectionPtr& conn,
						const MessagePtr& message,
						Timestamp now)
{//FIXME:error check
	int32_t id = message->id();
	if (message->type() == RESPONSE)
	{	
		ResponseDone::const_iterator it = responseDoneMap_.find(id);
		
		assert(it != responseDoneMap_.end());
		it->first()->ParseFromString(message->contend());//response			
		::google::protobuf::Closure* done = it->second();
		responseDoneMap_.erase(it); //FIXME:unsafe
		done->run();
	}
	else if (message->type() == REQUEST)
	{
		ServicesMap::const_iterator it = services_.find(message->service());
		
		assert(it != services_.end());
		::google::protobuf::Service service = *it;
		const ::google::protobuf::MethodDescriptor* method = service->GetDescriptor()->FindMethodByName(message->method());
		assert(method);
		boost::scoped_ptr<::google::protobuf::Message> request(service->GetRequestPrototype()->New());
		//automatically delete
		::google::protobuf::Message* response = service->GetResponsePrototype()->New();
		//automatically delete by doneCallback
		request->ParseFromString(message->contend());

		service->CallMethod(method,NULL,request,response,NewCallback(this,&doneCallback,response,id));
	}
}

void RpcChannel::registerService(::google::protobuf::Service* service)
{
	services_[service->name()] = service;
}

void RpcChannel::doneCallback(::google::protobuf::Message* response,
							  int32_t id)
{
	boost::scoped_ptr<::google::protobuf::Message> deletor(response);
	RpcMessage message;
	message.set_type(RESPONSE);
	message.set_id(id);
	message.set_contend(response->SerializeToString());
	codec_.send(message,conn_);
}
	
