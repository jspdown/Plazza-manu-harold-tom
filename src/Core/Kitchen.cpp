
#include	<sstream>
#include	<iostream>
#include	"Time.hh"
#include	"Trame.hh"
#include	"Convert.hh"
#include	"Manager.hh"
#include	"Kitchen.hh"

UnixMutex	*Kitchen::c_mutex = new UnixMutex(0);

void	*sender(void *data)
{
  Kitchen	*k = reinterpret_cast<Kitchen *>(data);
  bool		done = false;
  while (!done)
    {
      k->getChief()->deliverPizza(&(k->pipe.second));
    }
  return (0);
}

void	*counter(void *data)
{
  Kitchen	*k = reinterpret_cast<Kitchen *>(data);
  Timer	*beg = new Timer(5);
  bool	done = false;
  Timer *now = new Timer(0);

  while (!done)
    {
      if (k->getChief()->getBuzyCooks() != 0)
	{
	  delete beg;
	  beg = new Timer(5);
	}
      if (beg->getTime()->tv_sec == now->getTime()->tv_sec)
	{
	  k->close();
	  done = true;
	}
      else
	{
	  delete now;
	  now = new Timer(0);
	}
    }
  return 0;
}

Kitchen::Kitchen(int nbr_cooks, int fd_in, int fd_out, int id) :
  nbr_cooks(nbr_cooks), chief(new Manager(nbr_cooks, this)), thread_sender(UnixThread(0, sender, reinterpret_cast<void *>(this), 0)), pipe(std::pair<NamedPipe, NamedPipe>(NamedPipe(fd_in), NamedPipe(fd_out)))
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
}

Kitchen::~Kitchen()
{

}

void	Kitchen::throwCounter()
{
  this->thread_counter = new UnixThread(0, counter, reinterpret_cast<void *>(this), 0);
}

void	Kitchen::run()
{
  bool	done = false;
  std::string	trame;
  std::string	cmd;

  this->throwCounter();
  while (!done)
    {
      trame = getOrder();
      std::vector<std::string>	untrame = Trame::unpack(trame);
      if (untrame.size() > 0)
	{
	  cmd = Trame::getCmd(trame);
	  if (cmd == "GetStat")
	    sendOrder(buildStat());
	  else if (cmd == "GetPizza")
	    this->chief->preparePizza(trame);
	  else if (cmd == "Destroy")
	    done = true;
	}
    }
}

void	Kitchen::close()
{
  std::stringstream	cmd;

  std::cout << "Closing" << std::endl;
  cmd << "Destroy[?]:" << this->pipe.first.getFd() << ":" << this->pipe.second.getFd() << std::endl;
  this->sendOrder(cmd.str());
  this->pipe.first << cmd.str();
  this->Kitchen::~Kitchen();
}

std::string	Kitchen::getOrder()
{
  std::string	res;

  this->pipe.first >> res;
  return (res);
}

void	Kitchen::sendOrder(const std::string &str)
{
  this->pipe.second << str;
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
      std::string	cmd("SendLog");
      std::string	str("[Kitchen m");
      str.append(Convert::intToString(this->kitchen_id));
      str.append("]\t[");
      str.append(msg);
      str.append("]\n");
      std::vector<std::string>	ret;

      ret.push_back(str);
      this->c_mutex->lock();
      this->sendOrder(Trame::pack(cmd, ret));
      this->c_mutex->unlock();
    }
}

int	Kitchen::getNbrPizzaPossible()
{
  return (this->nbr_cooks * 2 - this->chief->getPreparingPizza());
}

Manager	*Kitchen::getChief()
{
  return (this->chief);
}

const char *Kitchen::KitchenError::what()	const throw()
{
  return ("[Error]:\tkitchen error");
}
