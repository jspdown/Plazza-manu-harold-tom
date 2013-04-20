
#include	<sstream>
#include	"Convert.hh"


int	Convert::stringToInt(const std::string &nbr)
{
  std::stringstream	ss;
  int			res;

  ss << nbr;
  ss >> res;
  return (res);
}

std::string	Convert::TaillePizzaToString(TaillePizza size)
{
  std::map<TaillePizza, std::string>	in;
  std::map<TaillePizza, std::string>::iterator	it;

  in[S] = std::string("S");
  in[M] = std::string("M");
  in[L] = std::string("L");
  in[XL] = std::string("XL");
  in[XXL] = std::string("XXL");

  it = in.find(size); 
  return ((it == in.end()) ? (std::string("Unknow")) : (it->second));
}

TaillePizza	Convert::stringToTaillePizza(const std::string &size)
{
  std::map<std::string, TaillePizza>	in;
  std::map<std::string, TaillePizza>::iterator	it;

  in[std::string("S")] = S;
  in[std::string("M")] = M;
  in[std::string("L")] = L;
  in[std::string("XL")] = XL;
  in[std::string("XXL")] = XXL;

  it = in.find(size);
  if (it == in.end())
    throw Convert::ConvertError();
  return (it->second);
}

std::string	Convert::TypePizzaToString(TypePizza size)
{
  std::string				res;
  std::map<TypePizza, std::string>	in;

  in[Americana] = std::string("Americana");
  in[Fantasia] = std::string("Fantasia");
  in[Margarita] = std::string("Margarita");
  in[Regina] = std::string("Regina");

  std::map<TypePizza, std::string>::iterator it = in.find(size); 
  return ((it == in.end()) ? (std::string("Unknow")) : (it->second));
}

std::string	Convert::TypeIngredientToString(TypeIngredient size)
{
  std::string				res;
  std::map<TypeIngredient, std::string>	in;
  std::map<TypeIngredient, std::string>::iterator	it;

  in[Doe] = std::string("Doe");
  in[Eggplant] = std::string("Eggplant");
  in[Goat_cheese] = std::string("Goat_cheese");
  in[Gruyere] = std::string("Gruyere");
  in[Ham] = std::string("Ham");
  in[Mushroom] = std::string("Mushroom");
  in[Steak] = std::string("Steak");
  in[Tomato] = std::string("Tomato");
  in[ChiefLove] = std::string("ChiefLove");

  it = in.find(size); 
  return ((it == in.end()) ? (std::string("Unknow")) : (it->second));
}


std::string	Convert::intToString(int nbr)
{
  std::stringstream	ss;
  std::string  		res;

  ss << nbr;
  ss >> res;
  return (res);
}

const char * Convert::ConvertError::what() const throw()
{
  return ("[Error] : bad conversion");
}
