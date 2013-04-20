
#ifndef		__COOK_HH__
# define	__COOK_HH__

#include	"ThreadDecorator.hh"

class	Cook: public ThreadDecorator
{
  Pizza	*pizza;
public:
  Cook();
  virtual ~Cook();
  Cook(const Cook &other);
  Cook	&operator=(const Cook &other);

  Pizza	*getPizza()	const;
  void	setPizza(Pizza *p);
};

#endif
