
#include	<iostream>
#include	"Trame.hh"
#include	"Convert.hh"
#include	"Manager.hh"
#include	"Kitchen.hh"

Kitchen::Kitchen(int nbr_cooks, NamedPipe *in, NamedPipe *out) :
  nbr_cooks(nbr_cooks), pipe(std::pair<NamedPipe *, NamedPipe *>(in, out)), chief(new Manager(nbr_cooks, this))
{
  this->ingredients[Doe] = 5;
  this->ingredients[Eggplant] = 5;
  this->ingredients[Goat_cheese] = 5;
  this->ingredients[Gruyere] = 5;
  this->ingredients[Ham] = 5;
  this->ingredients[Mushroom] = 5;
  this->ingredients[Steak] = 5;
  this->ingredients[Tomato] = 5;
  this->ingredients[ChiefLove] = 5;
}

Kitchen::~Kitchen()
{

}

void	Kitchen::run()
{
  bool	done = false;
  std::string	trame;

  while (!done)
    {
      trame = getOrder();
      if (Trame::unpack(trame)[0] == "GetStat")
	sendOrder(buildStat());
      else if (Trame::unpack(trame)[0] == "GetPizza")
	this->chief->preparePizza(trame);
      else
	std::cout << "unknow cmd" << std::endl;
      this->chief->deliverPizza();
    }
}

void	Kitchen::close()
{
  std::cout << "close" << std::endl;
}

std::string	Kitchen::getOrder()
{
  return (this->pipe.first->get());
}

void	Kitchen::sendOrder(const std::string &str)
{
  this->pipe.second->put(str);
  std::cout << "send order [" << str << "]" << std::endl;
}

std::map<TypeIngredient, int>	Kitchen::getIngredients()	const
{
  return (this->ingredients);
}

void	Kitchen::incressIngredients()
{
  for (std::map<TypeIngredient, int>::iterator it = this->ingredients.begin();
       it != this->ingredients.end(); ++it)
    it->second = it->second + 1;
}

bool	Kitchen::canCookPizza(Pizza *p)
{
  std::map<TypeIngredient, int>	recipe;

recipe = p->getRecipe();
  for (std::map<TypeIngredient, int>::const_iterator it = recipe.begin(); it != recipe.end(); ++it)
    {
if (this->ingredients[it->first] < it->second)
  return (false);
    }
  return (true);
}

std::string	Kitchen::buildStat()
{
  int	free_cooks = this->chief->getFreeCooks();
  int	buzy_cooks = this->chief->getBuzyCooks();
  int	possible_pizza = this->nbr_cooks * 2 - this->chief->getPreparingPizza();
  
  std::vector<std::string>	elms;
  std::vector<std::string>	ingr;

  elms.push_back(Convert::intToString(free_cooks));
  elms.push_back(Convert::intToString(buzy_cooks));
  elms.push_back(Convert::intToString(possible_pizza));
  this->chief->fillReport(elms);
  
  for (std::map<TypeIngredient, int>::const_iterator it = this->ingredients.begin(); it != this->ingredients.end(); ++it)
    {
      std::vector<std::string>	ins;
      ins[0] = Convert::TypeIngredientToString(it->first);
      ins[1] = Convert::intToString(it->second);
      ingr.push_back(Trame::group(ins, "|"));
    }
  elms.push_back(Trame::group(ingr, "@"));
  return (Trame::pack("SendStat", elms));
}
