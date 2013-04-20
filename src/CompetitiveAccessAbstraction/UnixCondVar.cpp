
#include <pthread.h>
#include "UnixCondVar.hh"

UnixCondVar::UnixCondVar()
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

int	UnixCondVar::wait()
{
  return pthread_cond_signal(&(this->condvar));
}

int	UnixCondVar::timedwait()
{
  return pthread_cond_signal(&(this->condvar));
}
