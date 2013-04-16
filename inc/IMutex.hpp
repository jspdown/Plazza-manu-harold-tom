#ifndef __I_MUTEX_HPP__
#define __I_MUTEX_HPP__

class IMutex
{
protected:
  virtual int	lock() = 0;
  virtual int	trylock() = 0;
  virtual int	unlock() = 0;
};

#endif // __I_MUTEX_HPP__
