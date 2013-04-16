#ifndef __UNIX_THREAD_HPP__
#define __UNIX_THREAD_HPP__

class UnixThread
{
public:
	UnixThread();
  	~UnixThread();
  int	create();
  void	exit();
  int	join();
  int	detach();
};

#endif // __UNIX_THREAD_HPP__
