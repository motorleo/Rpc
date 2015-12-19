#include <muduo/net/Buffer.h>
#include "ProtobufCodec.h"

namespace maxiaoda
{

using namespace muduo;
using namespace muduo::net;

ProtobufCodec::ProtobufCodec(const ProtobufMessageCallback& callback)
	:messageCallback_(callback)
{
}

void ProtobufCodec::send(const ::google::protobuf::Message& message,
						 const TcpConnectionPtr& conn)
{
	Buffer buf;
	int size = message.ByteSize();
	message.SerializeToArray(buf.beginWrite(),size);
	buf.hasWritten(size);
	buf.prependInt32(static_cast<int32_t>(size));
	conn->send(&buf);
}

void ProtobufCodec::messageCallback(const TcpConnectionPtr& conn,
									Buffer* buf,
									Timestamp now)
{
	while (buf->readableBytes() > kHeader) //not allowed for empty package
	{
		size_t len = static_cast<size_t>(buf->peekInt32());
		if (kMaxMessage <= len || len <= kMinMessage)
		{
			//error check
		}
		else if (buf->readableBytes() >= len + kHeader)
		{
			RpcMessage message;
			buf->retrieve(kHeader);
			message.ParseFromArray(buf->peek(),len);
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
