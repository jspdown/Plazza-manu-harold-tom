#include "UnixProcess.hh"

UnixProcess::UnixProcess()
{
  this->pid = getpid();
}

UnixProcess::UnixProcess(pid_t pid)
  : pid(pid)
{
}

UnixProcess::~UnixProcess()
{
}

IProcess *	UnixProcess::fork()
{
  pid_t	pid;

  pid = fork();
  if (pid < 0)
    {
      std::cerr << "Error : 'fork' failed." <<std::endl;
      return 0;
    }
  else
    return new UnixProcess(pid);
}

void		UnixProcess::exit(int return_value)
{
  exit(return_value)
}
