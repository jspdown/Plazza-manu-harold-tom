
#ifndef		__TASK_HH__
# define	__TASK_HH__

#include	<string>
#include	"UnixMutex.hh"
#include	<map>

class	Task;


class	Task
{
  static UnixMutex				mutex;
  std::string	preparePizza(const std::string &arg);
public:
  typedef       std::string    (Task::*Action)(const std::string&);
  Task(const std::string &cmd, const std::string &arg);
  ~Task();
  Task(const Task &other);
  Task	&operator=(const Task &other);

  std::string  	run();
  std::string	getArg()	const;

private:
  std::map<std::string, Action>	functions;
  Action			foo;
  std::string			arg;

};

#endif
