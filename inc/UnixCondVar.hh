#ifndef __UNIX_CONDVAR_HPP__
#define __UNIX_CONDVAR_HPP__

#include	<pthread.h>

#include	"ICondVar.hh"

class UnixCondVar: public ICondVar
{
  pthread_cond_t	condvar;
  size_t       		id;

public:
		~UnixCondVar();
		UnixCondVar(size_t);
  int		signal();
  int		broadcast();
  int		wait(IMutex *);
  int		timedwait(IMutex *, Timer *);
  pthread_cond_t *	getCondVar();
};

#endif // __UNIX_CONDVAR_HPP__
