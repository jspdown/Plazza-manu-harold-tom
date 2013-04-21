
#include	<iostream>
#include	<sys/time.h>
#include	<vector>
#include	<iostream>
#include	"Task.hh"
#include	"UnixThread.hh"
#include	"UnixMutex.hh"
#include	"UnixCondVar.hh"
#include	"ThreadPool.hh"

ThreadPool::ThreadPool(size_t nbr_thread) :
  nbr_thread(nbr_thread), nbr_thread_buzy(0)
{
  this->mutex = new UnixMutex(0);
  for (size_t i = 0; i < nbr_thread; ++i)
    {
      Arg * a = new Arg(this, i);
      this->thread.push_back(new UnixThread(0, execute, reinterpret_cast<void *>(a), i));
    }
  for (size_t i = 0; i < nbr_thread; ++i)
    this->mutexes.push_back(new UnixMutex(i));
  for (size_t i = 0; i < nbr_thread; ++i)
    this->condvars.push_back(new UnixCondVar(i));
}

ThreadPool::~ThreadPool()
{
  for (size_t i = 0; i < this->thread.size(); ++i)
    {
      delete this->thread[i];
    }
}

void	ThreadPool::add_action(Task *t)
{
  std::cout << "add action" << std::endl;
  this->mutex->lock();
  this->actions.push_back(t);
  this->mutex->unlock();
}

bool	ThreadPool::run_action(size_t & id)
{
  Task			*t;
  bool			ret;
  int			retcode;

  t = 0;
  this->mutex->lock();
  ret = !this->actions.empty();
  if (ret)
    {
      t = this->actions[0];
      this->actions.pop_front();
    }
  this->mutex->unlock();
  if (t)
    {
      ++(this->nbr_thread_buzy);
      this->ressources.push_back(t->run());

      // warning : le 0 en temps de cuisson de la pizza
      Timer    	time(3);
      std::cout << "before kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk" << std::endl;
      this->mutexes[id]->lock();
      std::cout << "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk" << std::endl;
      retcode = 0;
      while (retcode == 0)
	{
	  retcode = this->condvars[id]->timedwait(this->mutexes[id], &time);
	}
      this->mutexes[id]->unlock();

      --(this->nbr_thread_buzy);
    }
  return (true);
}

int	ThreadPool::getNbrThread()	const
{
  return (this->nbr_thread);
}

int	ThreadPool::getNbrThreadBuzy()	const
{
  return (this->nbr_thread_buzy);
}

void	*execute(void *data)
{
  Arg	*t = reinterpret_cast<Arg *>(data);

  while (t->pool->run_action(t->id));
  return (0);
}

Arg::Arg(ThreadPool *pool, size_t id)
  : pool(pool),
    id(id)
{
}
std::deque<std::string>	ThreadPool::getRessources() const 
{
  return (this->ressources);
}

void			ThreadPool::freeRessources()
{
  this->ressources.clear();
}
