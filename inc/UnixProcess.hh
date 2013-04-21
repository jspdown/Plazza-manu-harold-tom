#ifndef __UNIX_PROCESS_HPP__
#define __UNIX_PROCESS_HPP__

#include	<utility>

#include	"IProcess.hh"
#include	"NamedPipe.hh"

class UnixProcess : public IProcess
{
private:
  pid_t					pid;
  std::pair<NamedPipe *, NamedPipe *>	*pipes;

public:
				UnixProcess();
				UnixProcess(pid_t pid);
  virtual			~UnixProcess();
  virtual IProcess *		fork();
  virtual void			quit(int return_value);
  virtual void			put(const std::string &);
  virtual std::string		get();
  virtual void			setPipe(int in_fd, int out_fd);
};

#endif // __UNIX_PROCESS_HPP__
