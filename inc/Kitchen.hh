
#ifndef		__KITCHEN_HH__
# define	__KITCHEN_HH__

#include	<map>
#include	<utility>
#include	"Pizza.hh"
#include	"NamedPipe.hh"

class	Manager;

class	Kitchen
{
  int						nbr_cooks;
  std::pair<NamedPipe *, NamedPipe *>		pipe;
  Manager					*chief;
  std::map<TypeIngredient, int>	ingredients;
public:
  Kitchen(int nbr_cooks, NamedPipe *in, NamedPipe *out);
  ~Kitchen();
  Kitchen(const Kitchen &other);
  Kitchen	&operator=(const Kitchen &other);
  
  void	close();
  std::string	getOrder();
  void		sendOrder(const std::string &);
  std::map<TypeIngredient, int>	getIngredients()	const;
  void		incressIngredients();
  bool		canCookPizza(Pizza *p);
  std::string	buildStat();
  void		run();
};

#endif
