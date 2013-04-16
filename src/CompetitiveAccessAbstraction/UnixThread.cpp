#include "UnixThread.hh"

UnixThread::UnixThread(pthread_attr_t attr, void *(*func)(void *), void *arg)
{
  pthread_create(this->thread, attr, func, arg);
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
