#include <pthread.h>


namespace maxiaoda
{
class MutexLock : public boost::noncopyable
{
public:
	MutexLock()
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
	}

	void unlock()
	{
		pthread_mutex_unlock(&mutex_);
	}

private:
	pthread_mutex_t mutex_;
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
		mutex_.unlock();
	}

private:
	MutexLock& mutex_;
};
}
