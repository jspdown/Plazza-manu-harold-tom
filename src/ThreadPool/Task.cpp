
#include	<iostream>
#include	<vector>
#include	<string>
#include	"Trame.hh"
#include	"Task.hh"

UnixMutex	Task::mutex(UnixMutex(0));

Task::Task(const std::string &name, const std::string &arg)
{
  this->functions[std::string("preparePizza")] = &Task::preparePizza;
  this->arg = arg;
  this->foo = &Task::preparePizza;//this->functions[name];
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
  std::vector<std::string> r = Trame::unpack(arg);
  if (r.size() == 3)
    {
      this->mutex.lock();
      std::cout << "[Pizza] " << r[1] << " " << r[2] << std::endl;
      this->mutex.unlock();
    }
  return (arg);
}
