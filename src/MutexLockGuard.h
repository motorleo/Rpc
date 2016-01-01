#include <pthread.h>
#include <boost/noncopyable.hpp>


namespace maxiaoda
{
class MutexLock : public boost::noncopyable
{
public:
	MutexLock()
		:isLock_(false)
	{
		pthread_mutex_init(&mutex_,NULL);
	}

	~MutexLock()
	{
		pthread_mutex_destroy(&mutex_);
	}

	void lock()
	{
		pthread_mutex_lock(&mutex_);
		isLock_ = true;
	}

	void unlock()
	{
		pthread_mutex_unlock(&mutex_);
		isLock_ = false;
	}

	bool isLock()
	{
		return isLock_;
	}

private:
	pthread_mutex_t mutex_;
	bool isLock_;
};

class MutexLockGaurd : public boost::noncopyable
{
public:
	MutexLockGaurd(MutexLock& mutex)
		:mutex_(mutex)
	{
		mutex_.lock();
	}

	~MutexLockGaurd()
	{
		unlock();
	}

	void unlock()
	{
		if (mutex_.isLock())
		{
			mutex_.unlock();
		}
	}
private:
	MutexLock& mutex_;
};
}
