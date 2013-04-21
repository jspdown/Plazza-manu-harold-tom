
#include <pthread.h>
#include "UnixThread.hh"

UnixThread::UnixThread(pthread_attr_t *attr, void *(*func)(void *), void *arg, size_t id)
  : id(id)
{
  pthread_create(&(this->thread), attr, func, arg);
}

UnixThread::~UnixThread()
{
  this->detach();
  this->exit();
}

void	UnixThread::exit()
{
  int	return_value;

  return_value = 0;
  pthread_exit((void *)&return_value);
}

int	UnixThread::join()
{
  return pthread_join(this->thread, NULL);
}

int	UnixThread::detach()
{
  return pthread_detach(this->thread);
}

const pthread_t *	UnixThread::getThread() const
{
  return &(this->thread);
}
