
#ifndef		__PIZZAHANDLER_HH__
# define	__PIZZAHANDLER_HH__

#include	<map>
#include	<string>
#include	"Pizza.hh"

class	PizzaHandler
{
  std::map<std::string, Pizza *>	pizza;
public:
  PizzaHandler();
  ~PizzaHandler();
  PizzaHandler(const PizzaHandler &);
  PizzaHandler &operator=(const PizzaHandler &);

  Pizza	*build(const std::string &name, TaillePizza size);
  void	learn(Pizza *p);
  void	unlearn(const std::string &name);
};

#endif
