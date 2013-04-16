#ifndef __I_MUTEX_HH__
#define __I_MUTEX_HH__

class IMutex
{
protected:
  virtual	~IMutex(){};
  virtual int	lock() = 0;
  virtual int	trylock() = 0;
  virtual int	unlock() = 0;
};

#endif // __I_MUTEX_HH__
