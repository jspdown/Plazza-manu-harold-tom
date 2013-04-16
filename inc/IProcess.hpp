#ifndef __I_PROCESS_HPP__
#define __I_PROCESS_HPP__

class IProcess
{
protected:
  virtual		~IProcess(){};
  virtual IProcess *	fork() = 0;
  virtual void		quit() = 0;
};

#endif // __I_PROCESS_HPP__
