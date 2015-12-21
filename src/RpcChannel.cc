#include "ProtobufCodec.h"
#include "RpcChannel.h"
#include <boost/bind.hpp>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/service.h>

namespace maxiaoda
{
using namespace muduo;
using namespace muduo::net;

RpcChannel::RpcChannel()
	:id_(-1),codec_(boost::bind(&RpcChannel::onRpcMessage,this,_1,_2,_3))
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
	request->SerializeToString(&str);
	message.set_contend(str);
	
	responseDoneMap_[id_] = std::make_pair(response,done);//FIXME:unsafe

	codec_.send(message,conn_);
}
	


void RpcChannel::onRpcMessage(const TcpConnectionPtr& conn,
						      const RpcMessage& message,
							  Timestamp now)
{//FIXME:error check
	int32_t id = message.id();
	if (message.type() == RESPONSE)
	{	
		ResponseDoneMap::iterator it = responseDoneMap_.find(id);
		assert(it != responseDoneMap_.end());
		::google::protobuf::Message* response = it->second.first;
		response->ParseFromString(message.contend());//response			
		::google::protobuf::Closure* done = it->second.second;
		if (done)
		{
			done->Run();
		}
		responseDoneMap_.erase(it); //FIXME:unsafe
	}
	else if (message.type() == REQUEST)
	{
		ServicesMap::const_iterator it = services_->find(message.service());
		
		assert(it != services_->end());
		::google::protobuf::Service* service = it->second;
		const ::google::protobuf::ServiceDescriptor* des = service->GetDescriptor();
		const ::google::protobuf::MethodDescriptor* method = des->FindMethodByName(message.method());
		assert(method);
		boost::scoped_ptr< ::google::protobuf::Message> request(service->GetRequestPrototype(method).New());
		//automatically delete
		::google::protobuf::Message* response = service->GetResponsePrototype(method).New();
		//automatically delete by doneCallback
		request->ParseFromString(message.contend());

		service->CallMethod(method,NULL,get_pointer(request),response,NewCallback(this,&RpcChannel::doneCallback,response,id));
	}
}

void RpcChannel::setServices(const ServicesMap* services)
{
	services_ = services;
}

void RpcChannel::doneCallback(::google::protobuf::Message* response,
							  int32_t id)
{
	boost::scoped_ptr< ::google::protobuf::Message> deletor(response);
	RpcMessage message;
	message.set_type(RESPONSE);
	message.set_id(id);
	std::string str;
	response->SerializeToString(&str);
	message.set_contend(str);
	codec_.send(message,conn_);
}
	
}//namespace maxiaoda
