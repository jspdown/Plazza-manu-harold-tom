#ifndef __TIME_HH__
#define __TIME_HH__

#include	<sys/time.h>

class Timer
{
  struct timeval	ctime;
  struct timespec	timer;

public:
  Timer(int);
  ~Timer();
  const struct timespec *	getTime() const;
};

#endif // __TIME_HH__
