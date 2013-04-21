
#include	<iostream>
#include	"Trame.hh"
#include	"Convert.hh"
#include	"Manager.hh"
#include	"Kitchen.hh"

UnixMutex	*Kitchen::c_mutex = new UnixMutex(0);

Kitchen::Kitchen(int nbr_cooks, NamedPipe *in, NamedPipe *out, int id) :
  nbr_cooks(nbr_cooks), pipe(std::pair<NamedPipe *, NamedPipe *>(in, out)), chief(new Manager(nbr_cooks, this)), log_file("kitchen_report", std::ifstream::out | std::ifstream::trunc)
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
  this->kitchen_id = id;
  if (!this->log_file.good())
    throw Kitchen::KitchenError();
}

Kitchen::~Kitchen()
{

}

void	Kitchen::run()
{
  bool	done = false;
  std::string	trame;
  std::string	cmd;

  while (!done)
    {
      trame = getOrder();
      std::cout << "trame is: " << trame << std::endl;
      std::vector<std::string>	untrame = Trame::unpack(trame);
      std::cout << "unpack ok: " << trame << std::endl;
      if (untrame.size() > 0)
	{
	  cmd = Trame::getCmd(trame);
	  std::cout << cmd<< std::endl;
	  if (cmd == "GetStat")
	    {
	      this->log("v'la le rapport chef!");
	      std::cout << "getStat" << std::endl;
	      sendOrder(buildStat());

	    }
	  else if (cmd == "GetPizza")
	    {
	      std::cout << "getPIZZA" << std::endl;
	      this->log("et une pizza au cheval! une !");
	      this->chief->preparePizza(trame);
	    }
	  else
	    this->log("je fais quoi la?");
	  this->chief->deliverPizza();
	}
    }
}

void	Kitchen::close()
{
  std::cout << "close" << std::endl;
}

std::string	Kitchen::getOrder()
{
  std::string	res;

  *(this->pipe.first) >> res;
  return (res);
}

void	Kitchen::sendOrder(const std::string &str)
{
  std::cout << "send order [" << str << "]" << std::endl;
  *(this->pipe.second) << str;
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
      ins.push_back(Convert::TypeIngredientToString(it->first));
      ins.push_back(Convert::intToString(it->second));
      ingr.push_back(Trame::group(ins, "|"));
    }
  elms.push_back(Trame::group(ingr, "@"));
  return (Trame::pack("SendStat", elms));
}

void		Kitchen::log(const std::string &msg)
{
  if(!msg.empty())
    {
      std::cout << this->kitchen_id << std::endl;
      this->c_mutex->lock();
      std::cout << "[Kitchen n" << this->kitchen_id << "]:\t[" << msg << "]" << std::endl;
      this->log_file << "[Kitchen n" << this->kitchen_id << "]:\t[" << msg << "]" << std::endl;
      this->c_mutex->unlock();
    }
}

const char *Kitchen::KitchenError::what()	const throw()
{
  return ("[Error]:\tkitchen error");
}
