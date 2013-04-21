#ifndef __I_PROCESS_HH__
#define __I_PROCESS_HH__

#include	<utility>
#include	<string>

#include	"NamedPipe.hh"

class IProcess
{
public:
  virtual			~IProcess(){};
  virtual IProcess *		fork() = 0;
  virtual void			quit(int) = 0;
  virtual void			put(const std::string &) = 0;
  virtual std::string	  	get() = 0;
  virtual void			setPipe(int in, int out) = 0;
};

#endif // __I_PROCESS_HH__
