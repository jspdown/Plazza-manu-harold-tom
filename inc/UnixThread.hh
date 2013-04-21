#ifndef __UNIX_THREAD_HH__
#define __UNIX_THREAD_HH__

#include	<pthread.h>

#include	"IThread.hh"

class UnixThread : public IThread
{
private:
  pthread_t	thread;
  size_t        id;

public:
  UnixThread(pthread_attr_t *attr, void *(*func)(void *), void *arg, size_t id);
  	~UnixThread();
  void	exit();
  int	join();
  int	detach();
  const pthread_t *	getThread() const;
};

#endif // __UNIX_THREAD_HH__
