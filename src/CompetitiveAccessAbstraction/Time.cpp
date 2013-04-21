#include	"Time.hh"

Timer::Timer(int seconds)
{
  gettimeofday(&(this->ctime), 0);
  this->timer.tv_sec = this->ctime.tv_sec + seconds;
}

Timer::~Timer()
{
}

const struct timespec *	Timer::getTime() const
{
  return &(this->timer);
}
