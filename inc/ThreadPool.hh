
#ifndef	__THREADPOOL_HH__
#define	__THREADPOOL_HH__

#include	<queue>

#include	"Task.hh"
#include	"IMutex.hh"

class	ThreadPool
{
  unsigned int			nbr_thread;
  unsigned int			nbr_thread_buzy;
  IMutex			*mutex;
  std::queue<Task *>		actions;
  std::vector<IThread *>       	thread;
public:
  ThreadPool(int nbr_thread);
  ~ThreadPool();
  void	add_action(Task *t);
  int	run_action();
  int	getNbrThread()	const;
  int	getNbrThreadBuzy()	const;
};

void	execute(void *data);

#endif
