
#include	<vector>
#include	<iostream>
#include	"Trame.hh"
#include	"Convert.hh"
#include	"PizzaHandler.hh"

PizzaHandler::PizzaHandler()
{
  std::map<TypeIngredient, int>	ame;
  std::map<TypeIngredient, int>	fan;
  std::map<TypeIngredient, int>	mar;
  std::map<TypeIngredient, int>	reg;
  
  ame[Doe] = 1; 
  ame[Tomato] = 1; 
  ame[Gruyere] = 1; 
  ame[Steak] = 1; 

  fan[Doe] = 1; 
  fan[Tomato] = 1; 
  fan[Eggplant] = 1; 
  fan[Goat_cheese] = 1; 
  fan[ChiefLove] = 1; 

  mar[Doe] = 1;
  mar[Tomato] = 1;
  mar[Gruyere] = 1;

  reg[Doe] = 1;
  reg[Tomato] = 1;
  reg[Gruyere] = 1;
  reg[Ham] = 1;
  reg[Mushroom] = 1;
  this->pizza["Margarita"] = new Pizza(Margarita, "Margarita", S, mar);
  this->pizza["Regina"] = new Pizza(Regina, "Regina", S, reg);
  this->pizza["Americana"] = new Pizza(Americana, "Americana", S, ame);
  this->pizza["Fantasia"] = new Pizza(Fantasia, "Fantasia", S, fan);
}

PizzaHandler::~PizzaHandler()
{

}

Pizza	*PizzaHandler::build(const std::string &name, TaillePizza size)
{
  std::map<std::string, Pizza *>::iterator	it;

  it = this->pizza.find(name);
  if (it == this->pizza.end())
    {
      std::cout << "pizza not found" << std::endl;
      return (0);
    }
  Pizza	*p = it->second->clone();
  p->setSize(size);
  std::cout << "pizza(" << p->getName() << ") size(" << p->getSizeText() << ")" << std::endl;
  return (p);
}

void	PizzaHandler::learn(Pizza *p)
{
  std::string	name = p->getName();
  std::map<std::string, Pizza *>::iterator	it;

  it = this->pizza.find(name);
  if (it == this->pizza.end())
    this->pizza[name] = p->clone();
}

void	PizzaHandler::unlearn(const std::string &name)
{
  std::map<std::string, Pizza *>::iterator	it;

  it = this->pizza.find(name);
  if (it != this->pizza.end())
    this->pizza.erase(it);
}

Pizza	*PizzaHandler::build(const std::string &trame)
{
  std::vector<std::string>	tmp;
  std::string	name;
  std::string	size;

  tmp = Trame::unpack(trame);
  if (tmp.size() == 3)
    return (this->build(tmp[1], Convert::stringToTaillePizza(tmp[2])));
  return (0);
}

