
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
  std::string				res;
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

std::string	Convert::TypePizzaToString(TypePizza size)
{
  std::string				res;
  std::map<TypePizza, std::string>	in;

  in[Americaine] = std::string("Americaine");
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
