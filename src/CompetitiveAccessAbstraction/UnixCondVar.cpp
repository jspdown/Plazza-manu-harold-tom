
#include <pthread.h>
#include "UnixCondVar.hh"

UnixCondVar::UnixCondVar(size_t id)
  : id(id)
{
}

UnixCondVar::~UnixCondVar()
{
}

int	UnixCondVar::signal()
{
  return pthread_cond_signal(&(this->condvar));
}

int	UnixCondVar::broadcast()
{
  return pthread_cond_broadcast(&(this->condvar));
}

int	UnixCondVar::wait(IMutex *mutex)
{
  return pthread_cond_wait(&(this->condvar), mutex->getMutex());
}

int	UnixCondVar::timedwait(IMutex *mutex, Timer *time)
{
  return pthread_cond_timedwait(&(this->condvar), mutex->getMutex(), time->getTime());
}

pthread_cond_t *	UnixCondVar::getCondVar()
{
  return &this->condvar;
}
