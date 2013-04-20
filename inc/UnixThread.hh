#ifndef __UNIX_THREAD_HH__
#define __UNIX_THREAD_HH__

#include	<pthread.h>

#include	"IThread.hh"

class UnixThread : public IThread
{
private:
  pthread_t	thread;

public:
	UnixThread(pthread_attr_t attr, void *(*func)(void *), void *arg);
  	~UnixThread();
  void	exit();
  int	join();
  int	detach();
};

#endif // __UNIX_THREAD_HH__
