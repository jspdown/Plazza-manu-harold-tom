#ifndef __I_THREAD_HH__
#define __I_THREAD_HH__

#include	<pthread.h>

class IThread
{
public:
  virtual	~IThread(){};
  virtual void	exit() = 0;
  virtual int	join() = 0;
  virtual int	detach() = 0;
  virtual const pthread_t *	getThread() const = 0;
};

#endif // __I_THREAD_HH__
