#ifndef __UNIX_PROCESS_HPP__
#define __UNIX_PROCESS_HPP__

#include "IProcess.hh"

class UnixProcess : public IProcess
{
private:
  pid_t	pid;

public:
		UnixProcess();
		UnixProcess(pid_t pid);
		~UnixProcess();
  IProcess *	fork();
  void		exit(int return_value);

};

#endif // __UNIX_PROCESS_HPP__
