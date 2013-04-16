#ifndef __UNIX_MUTEX_HPP__
#define __UNIX_MUTEX_HPP__

#include <pthread.h>

#include "IMutex.hpp"

class UnixMutex : public Imutex
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

#endif // __UNIX_MUTEX_HPP__
