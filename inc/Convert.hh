
#ifndef		__CONVERT_H__
# define	__CONVERT_H__

#include	<exception>
#include	<string>
#include	"Pizza.hh"

class	Convert
{
public:
  class ConvertError: public std::exception
  {
  public:
    const char * what() const throw();
  };
  static int		stringToInt(const std::string &nbr);

  static TaillePizza		stringToTaillePizza(const std::string &size);

  static std::string	TypePizzaToString(TypePizza p);
  static std::string	TaillePizzaToString(TaillePizza t);
  static std::string	TypeIngredientToString(TypeIngredient i);
  static std::string	intToString(int);
};
#endif
