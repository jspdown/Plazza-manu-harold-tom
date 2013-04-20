
#include <iostream>
#include <vector>

#include "CmdLineParse.hh"
#include "Reception.hh"
#include "UnixProcess.hh"

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
//   std::pair<NamedPipe, NamedPipe>	pipes;
//   IProcess *				son;

//   namein << "InputKitchen" << num;
//   nameout << "OutputKitchen" << num;
//   pipes = std::make_pair(NamedPipe in(namein), NamedPipe out(nameout));
//   this->pipe.push_back(pipes);
//   son = this->process->fork();
//   son->setPipe(pipes);
//   this->processes.push_back(son);
//   num += 1;
// }

// void	Reception::deliverPizza(Pizza *pizza)
// {
//   std::cout << "Service d'une "
// 	    << pizza->getName()
// 	    << " "
// 	    << pizza->getSizeText()
// 	    << std::endl;
//   pizza->Pizza::~Pizza();
// }

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
