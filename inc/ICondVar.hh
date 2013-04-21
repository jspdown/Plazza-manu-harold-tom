#ifndef __I_CONDVAR_HH__
#define __I_CONDVAR_HH__

#include	"IMutex.hh"
#include	"Time.hh"

class ICondVar
{
public:
  virtual		~ICondVar(){};
  virtual int		signal() = 0;
  virtual int		broadcast() = 0;
  virtual int		wait(IMutex *) = 0;
  virtual int		timedwait(IMutex *, Timer *) = 0;
  virtual pthread_cond_t *	getCondVar() = 0;
};

#endif //__I_CONDVAR_HH__
