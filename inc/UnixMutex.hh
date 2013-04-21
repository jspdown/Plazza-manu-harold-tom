#ifndef __UNIX_MUTEX_HH__
#define __UNIX_MUTEX_HH__

#include	<pthread.h>

#include	"IMutex.hh"

class UnixMutex : public IMutex
{
  pthread_mutex_t	mutex;
  size_t       		id;

public:
	UnixMutex(size_t);
	~UnixMutex();
  int	lock();
  int	trylock();
  int	unlock();
  pthread_mutex_t * getMutex();
};

#endif // __UNIX_MUTEX_HH__
