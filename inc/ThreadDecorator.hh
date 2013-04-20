
#ifndef		__THREADDECORATOR_HH__
# define	__THREADDECORATOR_HH__

#include	"IThread.hh"

class	ThreadDecorator: public IThread
{
  IThread	*base;
public:
  ThreadDecorator(IThread *base)
  virtual ~ThreadDecorator();
  ThreadDecorator(const ThreadDecorator &other);
  ThreadDecorator	&operator=(const ThreadDecorator &other);

  IThread	*getBase()	const;
};

#endif
