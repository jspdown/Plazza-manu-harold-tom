#ifndef __I_CONDVAR_HPP__
#define __I_CONDVAR_HPP__

class ICondVar
{
protected:
  virtual	~ICondVar() = 0;
  virtual int	signal() = 0;
  virtual int	broadcast() = 0;
  virtual int	wait() = 0;
  virtual int	timedwait() = 0;
};

#endif //__I_CONDVAR_HPP__
