
#include	<vector>
#include	"Task.hh"
#include	"UnixThread.hh"
#include	"UnixMutex.hh"
#include	"ThreadPool.hh"

void	*execute(void *data)
{
  ThreadPool	*t = reinterpret_cast<ThreadPool *>(data);
  
  while (t->run_action());
  return (0);
}

ThreadPool::ThreadPool(size_t nbr_thread) :
  nbr_thread(nbr_thread), nbr_thread_buzy(0)
{
  this->mutex = new UnixMutex();
  for (size_t i = 0; i < nbr_thread; ++i)
    this->thread.push_back(new UnixThread(0, execute, reinterpret_cast<void *>(this)));
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
  this->mutex->lock();
  this->actions.push_back(t);
  this->mutex->unlock();
}

bool	ThreadPool::run_action()
{
  Task	*t;
  bool	ret;

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
      --(this->nbr_thread_buzy);
    }
  return (ret);
}

int	ThreadPool::getNbrThread()	const
{
  return (this->nbr_thread);
}

int	ThreadPool::getNbrThreadBuzy()	const
{
  return (this->nbr_thread_buzy);
}
