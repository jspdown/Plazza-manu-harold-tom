#include "UnixProcess.hh"
#include <algorithm>

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

IProcess *		UnixProcess::fork()
{
  pid_t	pid;

  pid = fork();
  if (pid < 0)
    {
      std::cerr << "Error : 'fork' failed." <<std::endl;
      return 0;
    }
  else if (pid == 0)
    return new UnixProcess(pid);
}

void			UnixProcess::exit(int return_value)
{
  exit(return_value)
}

void			UnixProcess::setPipe(std::pair<NamedPipe, NamedPipe> & pipes)
{
  this->pipes = pipes;
}

void			UnixProcess::put(const std::string & msg)
{
  std::vector<std::string>	trame;

  trame = CmdLineParser::CmdLineToTrame(msg);
  for_each(trame.begin(), trame.end(), (this->pipes.first())->put);
}

const std::string &    	UnixProcess::get()
{
  std::string	msg;

  msg = (this->pipes.second())->get;
}
