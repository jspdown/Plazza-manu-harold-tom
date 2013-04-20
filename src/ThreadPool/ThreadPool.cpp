
#include	"ThreadPool.hh"

void	execute(void *data)
{
  ThreadPool	*t = reinterpret_cast<ThreadPool *>(data);
  
  while (t->run_action());
}

ThreadPool::ThreadPool(int nbr_thread) :
  nbr_thread(nbr_thread), nbr_thread_buzy(0)
{
  this->mutex = new UnixMutex();
  for (unsigned int i = 0; i < nbr_thread; ++i)
    this->thread.push_back(new UnixThread(0, execute, this));
}

ThreadPool::~ThreadPool()
{
  for (std::vector<IThread *>::const_iterator it = this->thread.begin(); it != this->thread.end(); ++it)
    {
      delete *it;
      this->thread.erase(it);
    }
}

void	ThreadPool::add_action(Task *t)
{
  this->mutex->lock();
  this->actions.push(t);
  this->mutex->unlock();
}

bool	ThreadPool::run_action()
{
  Task	*t;
  bool	ret;

  t = 0;
  this->mutex->lock();
  ret = !this->actions.empty;
  if (ret)
    {
      t = this->actions.front();
      this->actions.pop();
    }
  this->mutex->unlock();
  if (t)
    {
      ++(this->nbr_thread_buzy);
      t->run();
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
