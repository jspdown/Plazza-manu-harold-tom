#ifndef __I_THREAD_HH__
#define __I_THREAD_HH__

class IThread
{
protected:
  virtual	~IThread(){};
  virtual void	exit() = 0;
  virtual int	join() = 0;
  virtual int	detach() = 0;
};

#endif // __I_THREAD_HH__
