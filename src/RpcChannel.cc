#include "ProtobufCodec.h"
#include "RpcChannel.h"

#include <boost/bind.hpp>

#include <muduo/base/Logging.h>

#include <google/protobuf/descriptor.h>
#include <google/protobuf/service.h>

namespace maxiaoda
{
RpcChannel::RpcChannel()
	:id_(-1),codec_(boost::bind(&RpcChannel::onRpcMessage,this,_1,_2,_3))
{
}

//inheritance
//for client
void RpcChannel::CallMethod(const ::google::protobuf::MethodDescriptor* method,
							::google::protobuf::RpcController* controller,
							const ::google::protobuf::Message* request,
							::google::protobuf::Message* response,
							::google::protobuf::Closure* done)
{
	RpcMessage message;
	message.set_type(REQUEST);
	message.set_service(method->service()->name());
	message.set_method(method->name());
	std::string str;
	if (!request->SerializeToString(&str))
	{
		errorCall(conn_,BAD_REQUEST);
		return;
	}
	message.set_contend(str);

	{
		MutexLockGaurd lock(mutex_);	
		message.set_id(++id_);
		responseDoneMap_[id_] = ::std::make_pair(response,done);
	}
	codec_.send(message,conn_);
}

void RpcChannel::onRpcMessage(const ::muduo::net::TcpConnectionPtr& conn,
						      const RpcMessage& message,
							  ::muduo::Timestamp now)
{
	assert(conn == conn_);
	int32_t id = message.id();
	if (message.type() == RESPONSE)
	{	
		::google::protobuf::Message* response;
		::google::protobuf::Closure* done;
		{
			MutexLockGaurd lock(mutex_);
			ResponseDoneMap::iterator it = responseDoneMap_.find(id);
			if (it == responseDoneMap_.end())
			{
				lock.unlock();
				errorCall(conn,BAD_RESPONSE);
				return;
			}
			response = it->second.first;
			done = it->second.second;
			responseDoneMap_.erase(it); 
		}
		if (!response->ParseFromString(message.contend()))
		{
			errorCall(conn,BAD_RESPONSE_PROTO);
			return;
		}
		if (done)
		{
			done->Run();
		}
	}
	else if (message.type() == REQUEST)
	{
		ServicesMap::const_iterator it = services_->find(message.service());
		if (it == services_->end())
		{
			errorSend(conn,SERVICE_NOT_FOUND,id);
			return;
		}
		::google::protobuf::Service* service = it->second;
		const ::google::protobuf::ServiceDescriptor* des = service->GetDescriptor();
		const ::google::protobuf::MethodDescriptor* method = des->FindMethodByName(message.method());
		if (method == NULL)
		{
			errorSend(conn,METHOD_NOT_FOUND,id);
			return;
		}
		boost::scoped_ptr< ::google::protobuf::Message> request(service->GetRequestPrototype(method).New());
		//automatically delete
		if (!request->ParseFromString(message.contend()))
		{
			errorSend(conn,BAD_REQUEST_PROTO,id);
			return;
		}
		::google::protobuf::Message* response = service->GetResponsePrototype(method).New();
		//automatically delete by doneCallback

		service->CallMethod(method,NULL,get_pointer(request),response,NewCallback(this,&RpcChannel::doneCallback,response,id));
	}
	else if (message.type() == ERROR)
	{
		errorCall(conn,message.error());
	}
}

void RpcChannel::setServices(const ServicesMap* services)
{
	services_ = services;
}

const char* RpcChannel::errorToString(ErrorReason error)
{
	switch (error)
	{
		case UNKNOW_ERROR :
			return "unknow error";
		case BAD_REQUEST :
			return "bad request";
		case BAD_RESPONSE :
			return "bad response";
		case SERVICE_NOT_FOUND :
			return "service not found";
		case METHOD_NOT_FOUND :
			return "method not found";
		case BAD_REQUEST_PROTO :
			return "bad request protocol";
		case BAD_RESPONSE_PROTO :
			return "bad response protocol";
	}
	return "unknow error";
}

void RpcChannel::errorCall(const ::muduo::net::TcpConnectionPtr& conn,
							ErrorReason error)
{
	LOG_WARN << "Rpc error for reason : " << errorToString(error);
	conn->shutdown();
}

void RpcChannel::errorSend(const ::muduo::net::TcpConnectionPtr& conn,
							ErrorReason error,
							int32_t id)
{
	RpcMessage message;
	message.set_type(ERROR);
	message.set_id(id);
	message.set_error(error);
	codec_.send(message,conn_);
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
