#ifndef __UNIX_MUTEX_HH__
#define __UNIX_MUTEX_HH__

#include <pthread.h>

#include "IMutex.hh"

class UnixMutex : public IMutex
{
private:
  pthread_mutex_t	mutex;

public:
	UnixMutex();
	~UnixMutex();
  int	lock();
  int	trylock();
  int	unlock();
};

#endif // __UNIX_MUTEX_HH__
