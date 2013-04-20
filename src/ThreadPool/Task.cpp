
#include	<iostream>
#include	<string>
#include	"Task.hh"

Task::Task(const std::string &name, const std::string &arg)
{
  this->functions[std::string("preparePizza")] = &Task::preparePizza;
  this->arg = arg;
  this->foo = this->functions[name];
   
}

Task::~Task()
{

}

std::string	Task::run()
{
  return (((this)->*(this->foo))(this->arg));
}

std::string	Task::getArg()	const
{
  return (this->arg);
}

std::string	Task::preparePizza(const std::string &arg)
{
  std::cout << "preparing pizza ... ou pas" << std::endl;
  return (arg);
}
