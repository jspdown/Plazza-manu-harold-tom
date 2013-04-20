#ifndef __UNIX_CONDVAR_HPP__
#define __UNIX_CONDVAR_HPP__

#include	<pthread.h>

#include	"ICondVar.hh"

class UnixCondVar: public ICondVar
{
private:
  pthread_cond_t	condvar;

public:
  	~UnixCondVar();
	UnixCondVar();
  int	signal();
  int	broadcast();
  int	wait();
  int	timedwait();
};

#endif // __UNIX_CONDVAR_HPP__
