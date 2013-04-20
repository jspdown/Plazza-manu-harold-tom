
#include	<iostream>
#include	"Manager.hh"

Manager::Manager(Kitchen *k) :
  kitchen(k)
{

}

Manager::~Manager()
{

}

void	Manager::preparePizza(const std::string &s)
{
  std::cout << "preparing pizza: " << s << std::endl;
}

void	Manager::deliverPizza(const std::string &s)
{
  std::cout << "sending pizza" << std::endl;
  this->kitchen->send(s);
}

