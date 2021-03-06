#include <sstream>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <algorithm>

#include "UnixProcess.hh"
#include "CmdLineParse.hh"

UnixProcess::UnixProcess()
{
  this->pid = getpid();
}

UnixProcess::UnixProcess(pid_t pid, size_t id)
  : pid(pid),
    id(id)
{
}

UnixProcess::~UnixProcess()
{
}

IProcess *		UnixProcess::fork()
{
  pid_t	pid;

  pid = ::fork();
  if (pid < 0)
    {
      std::cerr << "Error : 'fork' failed." <<std::endl;
      return 0;
    }
  else if (pid == 0)
    {
      IProcess	*pr = new UnixProcess(pid, 0);
      return (pr);
    }
  return (0);
}

void			UnixProcess::quit(int return_value)
{
  exit(return_value);
}

void			UnixProcess::setPipe(int fd_in, int fd_out)
{
  NamedPipe *in = new NamedPipe(fd_in);
  NamedPipe *out = new NamedPipe(fd_out);
  this->pipes = new std::pair<NamedPipe *, NamedPipe *>(in, out);
}

void			UnixProcess::put(const std::string & msg)
{
  std::vector<std::string>	trame;

  trame = CmdLineParse::CmdLineToTrame(msg);
  for (size_t i = 0; i < trame.size(); ++i)
    this->pipes->first->put(trame[i]);
      //  std::for_each(trame.begin(), trame.end(), (this->pipes.first())->put);
}

std::string    	UnixProcess::get()
{
  std::string	msg;

  msg = this->pipes->second->get();
  return (msg);
}
