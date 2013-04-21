#include <sstream>
#include <iostream>
#include <vector>
#include <utility>

#include "Trame.hh"
#include "Convert.hh"
#include "CmdLineParse.hh"
#include "PizzaHandler.hh"
#include "Reception.hh"
#include "UnixProcess.hh"
#include "IProcess.hh"
#include "Kitchen.hh"
#include "InputOutput.hh"

void	*delivery(void *data)
{
  Reception	*tp = reinterpret_cast<Reception *>(data);
  tp->getPizza();
  return (0);
}

Reception::Reception(int nbr_cooks)
  : delivery_man(UnixThread(0, delivery, reinterpret_cast<void *>(this), 0)),
    process(new UnixProcess()),
    nbr_cooks(nbr_cooks)
{
  
}

Reception::~Reception()
{
}

void	Reception::createKitchen()
{
  static int				num;
  std::stringstream			namein;
  std::stringstream			nameout;
  std::pair<NamedPipe *, NamedPipe *>	*pipes;
  IProcess *				son;
  
  std::cout << "create kitchen" << std::endl;
  namein << "InputKitchen" << num;
  nameout << "OutputKitchen" << num;
  NamedPipe *in = new NamedPipe(namein.str());
  NamedPipe *out = new NamedPipe(nameout.str());
  pipes = new std::pair<NamedPipe *, NamedPipe *>(in, out);
  this->pipe.push_back(pipes);
  if ((son = this->process->fork()))
    {
      son->setPipe(in->getFd(), out->getFd());
      Kitchen * k = new Kitchen(this->nbr_cooks, pipes->first, pipes->second);
      k->run();
      this->processes.push_back(son);
    }
  num += 1;
}

void	Reception::deliverPizza(Pizza *pizza)
{
  std::stringstream	msg;
  
  msg << "Service d'une "
      << pizza->getName()
      << " "
      << pizza->getSizeText()
      << std::endl;
  this->io.write(msg.str());
}

void	Reception::run()
{
  bool	done = false;

  this->createKitchen();
  while (!done)
    {
      this->getOrder();
    }
}

void	Reception::destroyKitchen(int pos)
{
  this->pipe.erase(this->pipe.begin() + pos);
}

void	Reception::getPizza()
{
  PizzaHandler		hp;

  for (size_t i = 0; i < this->pipe.size(); ++i)
    {
      std::string	res;

      res = this->pipe[i]->second->get();
      std::vector<std::string>	r = Trame::unpack(res);
      if (r.size() == 3 && Trame::getCmd(r[0]) == "GetPizza")
	this->deliverPizza(hp.build(r[0], Convert::stringToTaillePizza(r[2])));
    }
}

void	Reception::getOrder()
{
  int				pos;
  std::string			msg;
  std::vector<std::string>	tramecmd;
  std::stringstream		msgstream;

  std::getline (std::cin, msg);
  tramecmd = CmdLineParse::CmdLineToTrame(msg);
  for (size_t i = 0; i < tramecmd.size(); ++i)
    {
      if ((pos = this->checkStatus()) < 0)
	{
	  std::cout << "not enough place, i must create a kitchen" << std::endl;
	  this->createKitchen();
	  pos = this->checkStatus();
	}
      this->pipe[pos]->first->put(tramecmd[i]);
    }
}

int	Reception::checkStatus() const
{
  std::vector<std::string>	trame;
  std::string			packedtrame;
  unsigned int 			i;
  std::string			answer;

  packedtrame = Trame::pack("GetStat", trame);
  for (i = 0; i < this->pipe.size(); i += 1)
    {
      (this->pipe[i]->first)->put(packedtrame);
      answer = (this->pipe[i]->second)->get();
      std::cout << "answer is : " << answer << std::endl;
      while (answer.empty())
	answer = (this->pipe[i]->second)->get();
      trame = Trame::unpack(answer);
      if (trame.size() >= 3 && trame[3].compare("0") != 0)
	return i;
    }
  return (-1);
}
