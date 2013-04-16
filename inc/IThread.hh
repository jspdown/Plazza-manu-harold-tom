#ifndef __I_THREAD_HPP__
#define __I_THREAD_HPP__

class IThread
{
protected:
  virtual	~IThread(){};
  virtual int	create() = 0;
  virtual void	exit() = 0;
  virtual int	join() = 0;
  virtual int	detach() = 0;
};

#endif // __I_THREAD_HPP__
