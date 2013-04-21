
#ifndef	__THREADPOOL_HH__
#define	__THREADPOOL_HH__

#include	<deque>
#include	<vector>

#include	"Task.hh"
#include	"IMutex.hh"
#include	"IThread.hh"
#include	"ICondVar.hh"

class	ThreadPool
{
protected:
  unsigned int			nbr_thread;
  unsigned int			nbr_thread_buzy;
  IMutex			*mutex;
  std::deque<Task *>		actions;
  std::deque<std::string>      	ressources;
  std::vector<IMutex *>		mutexes;
  std::vector<IThread *>       	thread;
  std::vector<ICondVar *>	condvars;

public:
  ThreadPool(size_t nbr_thread);
  ~ThreadPool();
  void	add_action(Task *t);
  bool	run_action(size_t &);
  int	getNbrThread()	const;
  int	getNbrThreadBuzy()	const;
  std::deque<std::string>	getRessources()	const;
  void			freeRessources();
};

class	Arg
{
public:
  ThreadPool	*pool;
  size_t	id;

  Arg(ThreadPool *, size_t);
  ~Arg();
};

void	*execute(void *data);

#endif
