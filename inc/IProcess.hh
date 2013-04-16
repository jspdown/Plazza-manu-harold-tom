#ifndef __I_PROCESS_HH__
#define __I_PROCESS_HH__

class IProcess
{
protected:
  virtual		~IProcess(){};
  virtual IProcess *	fork() = 0;
  virtual void		quit(int) = 0;
};

#endif // __I_PROCESS_HH__
