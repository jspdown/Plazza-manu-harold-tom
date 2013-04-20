
#ifndef		__KITCHEN_HH__
# define	__KITCHEN_HH__

#include	<map>
#include	<utility>
#include	"Pizza.hh"
#include	"Manager.hh"

class	Kitchen
{
  Manager					chief;
  std::map<std::pair<TypeIngredient, int> >	ingredients;
public:
  Kitchen();
  ~Kitchen();
  Kitchen(const Kitchen &other);
  Kitchen	&operator=(const Kitchen &other);
  
  void	close();
  void	checkOrder();
  void	sendOrder(const std::string &);
  std::map<std::pair<TypeIngredient, int> >	getIngredients()	const;
};

#endif
