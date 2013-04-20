#include <sstream>
#include <iostream>
#include <vector>
#include <utility>

#include "CmdLineParse.hh"
#include "Reception.hh"
#include "UnixProcess.hh"
#include "IProcess.hh"
//#include "Kitchen.hh"

Reception::Reception()
  : process(new UnixProcess())
{
}

Reception::~Reception()
{
}

// void	Reception::createKitchen()
// {
//   static int				num;
//   std::stringstream			namein;
//   std::stringstream			nameout;
//   std::pair<NamedPipe *, NamedPipe *>	pipes;
//   IProcess *				son;

//   namein << "InputKitchen" << num;
//   nameout << "OutputKitchen" << num;
//   NamedPipe in(namein.str());
//   NamedPipe out(nameout.str());
//   pipes = std::make_pair(&in, &out);
//   this->pipe.push_back(pipes);
//   son = this->process->fork();
//   son->setPipe(pipes);
//   new Kitchen(&(pipes.first), &(pipes.second));
//   this->processes.push_back(son);
//   num += 1;
// }

void	Reception::deliverPizza(Pizza *pizza)
{
  std::cout << "Service d'une "
	    << pizza->getName()
	    << " "
	    << pizza->getSizeText()
	    << std::endl;
  pizza->Pizza::~Pizza();
}

void	Reception::run()
{
  std::string			msg;
  std::vector<std::string>	tramecmd;

  while (true)
    {
      std::getline (std::cin, msg);
      tramecmd = CmdLineParse::CmdLineToTrame(msg);
      for (size_t i = 0; i < tramecmd.size(); ++i)
	{
	  std::cout << tramecmd[i] << std::endl;
	}
    }
}

// void	Reception::destroyKitchen(int pos)
// {
//   this->pipe.erase(this->pipe.begin() + pos);
// }

void	Reception::transferOrder()
{

}

int	Reception::checkStatus()
{
  std::vector<std::string>	trame;
  return (1);
}
