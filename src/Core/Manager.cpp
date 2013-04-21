
#include	<iostream>
#include	"Manager.hh"

Manager::Manager(size_t nbr_cooks, Kitchen *k) :
  ThreadPool(nbr_cooks), kitchen(k)
{

}

Manager::~Manager()
{

}

void	Manager::preparePizza(const std::string &s)
{
  std::string	cmd = Trame::getCmd(s);
  Task		*t = new Task(cmd, s);
  
  this->add_action(t);
}

void	Manager::deliverPizza(NamedPipe *out)
{
  for (size_t i = 0; i < this->ressources.size(); ++i)
    {
      out->put(this->ressources[i]);
    }
  this->freeRessources();
}

void	Manager::fillReport(std::vector<std::string> report)
{
  std::vector<std::string>	orders;

  for (size_t i = 0; i < this->actions.size(); ++i)
    {
      std::string	arg = this->actions[i]->getArg();
      std::vector<std::string> rs = Trame::unpack(arg);
      orders.push_back(Trame::group(rs, "|"));
    }
  report.push_back(Trame::group(orders, "@"));
}

int	Manager::getFreeCooks()	const
{
  return (this->nbr_thread - this->nbr_thread_buzy);
}
int	Manager::getBuzyCooks()	const
{
  return (this->nbr_thread_buzy);
}
int	Manager::getPreparingPizza()	const
{
  return (this->actions.size() + this->nbr_current_action);
}

