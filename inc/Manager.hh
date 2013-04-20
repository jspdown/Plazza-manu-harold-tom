
#ifndef		__MANAGER_HH__
# define	__MANAGER_HH__

#include	"ThreadPool.hh"
#include	"Kitchen.hh"

class	Manager: public	ThreadPool
{
  Kitchen	*kitchen;
public:
  Manager(Kitchen *k);
  ~Manager();
  Manager(const Manager &other);
  Manager	&operator=(const Manager &other);

  void	preparePizza(const std::string &s);
  void	deliverPizza(const std::string &s);
};

#endif
