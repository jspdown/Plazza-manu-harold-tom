#include <sstream>
#include <iostream>
#include <vector>
#include <utility>

#include "Trame.hh"
#include "CmdLineParse.hh"
#include "Reception.hh"
#include "UnixProcess.hh"
#include "IProcess.hh"
#include "Kitchen.hh"
#include "InputOutput.hh"

Reception::Reception(int nbr_cooks)
  : process(new UnixProcess()),
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

  namein << "InputKitchen" << num;
  nameout << "OutputKitchen" << num;
  NamedPipe *in = new NamedPipe(namein.str());
  NamedPipe *out = new NamedPipe(nameout.str());
  pipes = new std::pair<NamedPipe *, NamedPipe *>(in, out);
  this->pipe.push_back(pipes);
  if ((son = this->process->fork()))
    {
      son->setPipe(pipes);
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
  pizza->Pizza::~Pizza();
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
	  this->createKitchen();
	  pos = this->checkStatus();
	}
      msgstream  << tramecmd[i] << std::endl;
      this->io.write(msgstream.str());
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
      while (answer.empty())
	answer = (this->pipe[i]->second)->get();
      trame = Trame::unpack(answer);
      if (trame.size() >= 3 && trame[2].compare("0") != 0)
	return i;
    }
  return (-1);
}
