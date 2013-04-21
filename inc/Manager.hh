
#ifndef		__MANAGER_HH__
# define	__MANAGER_HH__

#include	"ThreadPool.hh"
#include	"Trame.hh"
#include	"Kitchen.hh"

class	Manager: public	ThreadPool
{
  Kitchen	*kitchen;
public:
  Manager(size_t nbr_cooks, Kitchen *k);
  ~Manager();
  Manager(const Manager &other);
  Manager	&operator=(const Manager &other);

  void	preparePizza(const std::string &s);
  void	deliverPizza(NamedPipe *p);

  void	fillReport(std::vector<std::string> report);

  int	getFreeCooks()	const;
  int	getBuzyCooks()	const;
  int	getPreparingPizza()	const;
};

#endif
