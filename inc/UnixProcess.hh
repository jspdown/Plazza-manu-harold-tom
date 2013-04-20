#ifndef __UNIX_PROCESS_HPP__
#define __UNIX_PROCESS_HPP__

#include <utility>

#include "IProcess.hh"
#include "NamedPipe.hh"

class UnixProcess : public IProcess
{
private:
  pid_t					pid;
  std::pair<NamedPipe, NamedPipe>	pipes;

public:
			UnixProcess();
			UnixProcess(pid_t pid);
  virtual		~UnixProcess();
  virtual IProcess *   	fork();
  virtual void	       	quit(int return_value);
  void			put(const std::string &);
  const std::string &	get();
  void			setPipe(std::pair<NamedPipe, NamedPipe> &);
};

#endif // __UNIX_PROCESS_HPP__
