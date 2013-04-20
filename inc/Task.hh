
#ifndef		__TASK_HH__
# define	__TASK_HH__

template <class T>
class	Task
{
  typedef       void    (T::*Action)(const std::string&);
  Action	func;
  std::string	arg;
public:
  Task();
  ~Task();
  Task(const Task<T> &other);
  Task<T>	&operator=(const Task<T> &other);

  void		run();
};

#endif
