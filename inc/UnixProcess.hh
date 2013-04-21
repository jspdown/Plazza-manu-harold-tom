#ifndef __UNIX_PROCESS_HPP__
#define __UNIX_PROCESS_HPP__

#include	<utility>

#include	"IProcess.hh"
#include	"NamedPipe.hh"

class UnixProcess : public IProcess
{
private:
  pid_t					pid;
<<<<<<< HEAD
  std::pair<NamedPipe *, NamedPipe *>	pipes;
  int					id;
=======
  std::pair<NamedPipe *, NamedPipe *>	*pipes;
>>>>>>> 07a1b3d746b6c16d7a6916f44437ea8da565919a

public:
				UnixProcess();
				UnixProcess(pid_t pid, size_t id);
  virtual			~UnixProcess();
  virtual IProcess *		fork();
  virtual void			quit(int return_value);
  virtual void			put(const std::string &);
  virtual std::string		get();
  virtual void			setPipe(std::pair<NamedPipe *, NamedPipe *> *);
};

#endif // __UNIX_PROCESS_HPP__
