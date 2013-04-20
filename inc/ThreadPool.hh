
#ifndef	__THREADPOOL_HH__
#define	__THREADPOOL_HH__

#include	<deque>
#include	<vector>

#include	"Task.hh"
#include	"IMutex.hh"
#include	"IThread.hh"

class	ThreadPool
{
protected:
  unsigned int			nbr_thread;
  unsigned int			nbr_thread_buzy;
  IMutex			*mutex;
  std::deque<Task *>		actions;
  std::deque<std::string>      	ressources;
  std::vector<IThread *>       	thread;
public:
  ThreadPool(size_t nbr_thread);
  ~ThreadPool();
  void	add_action(Task *t);
  bool	run_action();
  int	getNbrThread()	const;
  int	getNbrThreadBuzy()	const;
};

void	*execute(void *data);

#endif
