
#include	<iostream>
#include	"PizzaHandler.hh"

PizzaHandler::PizzaHandler()
{
  std::map<TypeIngredient, int>	ame;
  std::map<TypeIngredient, int>	fan;
  
  ame[Doe] = 1; 
  ame[Ham] = 2; 
  fan[Doe] = 4; 
  fan[Ham] = 4; 
  this->pizza["Americaine"] = new Pizza(Americaine, "Americaine", S, ame);
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
