#include <muduo/net/Buffer.h>

using namespace muduo;
using namespace muduo::net;

ProtobufCodec::ProtobufCodec(const ProtobufMessageCallback& callback)
	:messageCallback_(callback);
{
}

void ProtobufCodec::send(const MessagePtr& message,
						 const TcpConnectionPtr& conn)
{
	Buffer buf;
	int size = message->ByteSize;
	message->SerializeToArray(buf.beginWrite(),size);
	buf->hasWritten(size);
	buf->prependInt32(sockets::hostToNetwork32(static_cast<int32_t>(size)));//FIXME:uint32_t
	conn->send(buf);
}

void messageCallback(const TcpConnectionPtr& conn,
					 Buffer* buf,
					 Timestamp now)
{
	while (buf->readableBytes() > kHeader) //not allowed for empty package
	{
		size_t

