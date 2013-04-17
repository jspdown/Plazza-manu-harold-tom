
#ifndef		__CONVERT_H__
# define	__CONVERT_H__

#include	<string>
#include	"Pizza.hh"

class	Convert
{
public:
  static int		stringToInt(const std::string &nbr);

  static std::string	TypePizzaToString(TypePizza p);
  static std::string	TaillePizzaToString(TaillePizza t);
  static std::string	TypeIngredientToString(TypeIngredient i);
  static std::string	intToString(int);
};
#endif
