#ifndef __UNIX_PROCESS_HPP__
#define __UNIX_PROCESS_HPP__

#include "IProcess.hpp"

class UnixProcess : public IProcess
{
private:
  pid_t	pid;

public:
		UnixProcess();
		~UnixProcess();
  IProcess *	fork();
  void		exit();

};

#endif // __UNIX_PROCESS_HPP__
