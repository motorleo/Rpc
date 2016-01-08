#include "ProtobufCodec.h"

#include <muduo/net/Buffer.h>
#include <muduo/base/Logging.h>

namespace maxiaoda
{
ProtobufCodec::ProtobufCodec(const ProtobufMessageCallback& callback)
	:messageCallback_(callback)
{
}

void ProtobufCodec::send(const ::google::protobuf::Message& message,
						 const ::muduo::net::TcpConnectionPtr& conn)
{
	::muduo::net::Buffer buf;
	int size = message.ByteSize();
	if (!message.SerializeToArray(buf.beginWrite(),size))
	{
		LOG_FATAL << "ProtobufCodec::send() : Message serialize to buffer error!";
	}
	buf.hasWritten(size);
	buf.prependInt32(static_cast<int32_t>(size));
	conn->send(&buf);
}

void ProtobufCodec::onMessage(const ::muduo::net::TcpConnectionPtr& conn,
						      ::muduo::net::Buffer* buf,
							  ::muduo::Timestamp now)
{
	while (buf->readableBytes() >= kHeader) //Allowed for empty package
	{
		size_t len = static_cast<size_t>(buf->peekInt32());
		if (kMaxMessage <= len || len <= kMinMessage)
		{
			LOG_WARN << "ProtobufCodec::onMessage() : Illegal package length!";
			conn->shutdown();
			return;
		}
		else if (buf->readableBytes() >= len + kHeader)
		{
			RpcMessage message;
			buf->retrieve(kHeader);
			if (!message.ParseFromArray(buf->peek(),static_cast<int>(len)))
			{
				LOG_WARN << "ProtobufCodec::onMessage() : Parse from buffer error!";
				conn->shutdown();
				return;
			}
			messageCallback_(conn,message,now);
			buf->retrieve(len);
		}
		else 
		{
			break;//wait for more data recieve
		}
	}
}
}//namespace maxiaoda
