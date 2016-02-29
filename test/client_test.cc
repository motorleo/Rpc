#include "test.pb.h"
#include "../src/RpcClientLite.h"
#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>

#include <stdio.h>
#include <time.h>
#include <vector>
#include <string>


#define TIMEOUT 20

using namespace maxiaoda;
using namespace muduo;
using namespace muduo::net;

class bench;

class testClient : public RpcClientLite
{
public:
    testClient(EventLoop* loop,const InetAddress& addr,bench* owner)
        :RpcClientLite(loop,addr),
		stub_(getChannel()),
		messagecount_(0),
		owner_(owner)
    {
    }

	int messagecount() { return messagecount_;}
private:
    virtual void initCallback(const TcpConnectionPtr& conn);
    
    void doneCallback(test::testMessage* request);

    test::testService_Stub stub_;
	time_t startTime_;
	int messagecount_;
	bench* owner_;
};

class bench
{
public:
	bench(EventLoop* loop,
			const InetAddress& addr,
			int nClient,
			int nMessageSize,
			int Timeout)
		:loop_(loop),testVec_(),string_(),ClientCount_(0),timeout_(Timeout)
	{
		for (int i = 0;i < nMessageSize;++i)
		{
			string_ += 'i';
		}

		while (++ClientCount_ <= nClient)
		{
			testClient* client = new testClient(loop,addr,this);
			client->connect();
			testVec_.push_back(client);
		}
		--ClientCount_;
	}

	int getTimeout() { return timeout_;}

	const std::string& getString() { return string_; }

	void onDisconnect()
	{
		if (--ClientCount_ == 0)
		{
			int messageCount = 0;
			std::vector<testClient*>::iterator iter = testVec_.begin();
			for (;iter < testVec_.end();++iter)
			{
				messageCount += (*iter)->messagecount();
				delete (*iter);
			}
			LOG_WARN << "all client done.";
			LOG_WARN << "Total send message:" << messageCount;
			LOG_WARN << static_cast<long long>(messageCount * string_.size()) / (getTimeout() * 1024 * 1024)
				     << " MB/s throughput.";
			LOG_WARN << messageCount / getTimeout() << " /s request.";
			loop_->quit();	
		}
	}

private:
	EventLoop* loop_;
	std::vector<testClient*> testVec_;
	std::string string_;
	int ClientCount_;
	int timeout_;
};

void testClient::initCallback(const TcpConnectionPtr& conn)
{   
	test::testMessage request;
	request.set_echostring(owner_->getString());
	test::testMessage* response(new test::testMessage());
	stub_.Echo(NULL,&request,response,NewCallback(this,&testClient::doneCallback,response));
	startTime_ = ::time(NULL);
}

void testClient::doneCallback(test::testMessage* request)
{   
	++messagecount_;
	if (time(NULL) - startTime_ < owner_->getTimeout())
	{
		if (request)
		{
			test::testMessage* response(new test::testMessage());
			stub_.Echo(NULL,request,response,NewCallback(this,&testClient::doneCallback,response));
		}
	}
	else
	{
		disconnect();
		owner_->onDisconnect();
	}
	delete request;
}

int main(int argc,char** argv)
{
	if (argc >= 5)
	{
		EventLoop loop;
		InetAddress address(argv[1],9981);
		int nClient = atoi(argv[2]);
		int MessageSize = atoi(argv[3]);
		int timeout = atoi(argv[4]);
		bench client(&loop,address,nClient,MessageSize,timeout);
		loop.loop();
	}
	else
	{
		printf("Usage:<%s> <host_ip> <nClient> <MessageSize> <Timeout>!\n",argv[0]);
	}
}
