
#include	<sstream>
#include	<iostream>
#include	<vector>
#include	<string>

#include	"CmdLineParse.hh"
#include	"Trame.hh"
#include	"UnixThread.hh"
#include	"UnixProcess.hh"
#include	"UnixMutex.hh"
#include	"Reception.hh"

void	*delivery(void *data)
{
  bool		done = false;
  Reception	*rp = reinterpret_cast<Reception *>(data);

  rp->throwReader();
  while (!done)
    {
      rp->fillRessources();
    }
  return (0);
}

void	*reader_action(void *data)
{
  bool		done = false;
  Reception	*rp = reinterpret_cast<Reception *>(data);

  while (!done)
    {
      rp->applyOutput(); 
    }
  return (0);
}


Reception::Reception(int nbr_cooks) :
  delivery_man(0, delivery, reinterpret_cast<void *>(this), 0), process(new UnixProcess()), nbr_cooks(nbr_cooks)
{

}

Reception::~Reception()
{
  
}

void		Reception::throwReader()
{
  this->reader = new UnixThread(0, reader_action, reinterpret_cast<void *>(this), 0);
}

void	Reception::fillRessources()
{
  for (size_t i = 0; i < this->pipe.size(); ++i)
    {
      std::string	trame = this->pipe[i]->second->get();
     
      if (trame != "")
	{
	  this->ressources.push_back(trame);
	}
    }
}

void	Reception::applyOutput()
{
  std::string	res;

  if (!this->ressources.empty())
    {
      std::string msg = this->ressources.front();
      if (Trame::getCmd(msg) == "GetPizza")
  	{
  	  this->ressources.pop_front();
  	}
      else if (Trame::getCmd(msg) != "SendStat")
  	this->ressources.pop_front();
    }
}

void	Reception::createKitchen()
{
  static int			       	num;
  std::stringstream			namein;
  std::stringstream			nameout;
  std::pair<NamedPipe *, NamedPipe *>	*pipes;
  IProcess				*son;
  
  namein << "InputKitchen" << num;
  nameout << "OutputKitchen" << num;
  NamedPipe *in = new NamedPipe(namein.str());
  NamedPipe *out = new NamedPipe(nameout.str());
  pipes = new std::pair<NamedPipe *, NamedPipe *>(in, out);
  std::pair<int, int>			fds(pipes->first->getFd(), pipes->second->getFd());
  this->pipe.push_back(pipes);
  if ((son = this->process->fork()))
    {
      Kitchen k = Kitchen(this->nbr_cooks, fds.first, fds.second, num);
      k.run();
      //pesnser a close les fds
      son->quit(1);
    }
    ++num;
}
  
std::vector<std::string>	Reception::getCmdLine()
{
  std::string	msg("");
  std::vector<std::string>	res;

  std::getline(std::cin, msg);
  res = CmdLineParse::CmdLineToTrame(msg);
  return (res);
}

std::string	Reception::searchTrame(const std::string &seek)
{
  std::deque<std::string>::iterator it = this->ressources.begin();
  std::deque<std::string>::iterator tmp;
  std::string			    answer;
  
  while (it != this->ressources.end())
    {
      if (Trame::getCmd(*it) == seek)
	{
	  answer = *it;
	  tmp = it;
	  ++it;
	  this->ressources.erase(tmp);
	  return (answer);
	}
      else
	++it;
    }
  return (std::string(""));
}


int	Reception::findKitchen()
{
  std::string	packedtrame;
  std::vector<std::string>	trame;
  std::string	msg;

  for (size_t i = 0; i < this->pipe.size(); ++i)
    {
      packedtrame = Trame::pack("GetStat", trame);
      this->pipe[i]->first->put(packedtrame);
      while ((msg = this->searchTrame("SendStat")) == "");
      std::vector<std::string> res_msg = Trame::unpack(msg);
      if (res_msg.size() == 5 && res_msg[3] != "0")
	return (i);
    }
  return (-1);
}

void	Reception::dispatch(std::vector<std::string> lines)
{
  int	idx;

  for (size_t i = 0; i < lines.size(); ++i)
    {
      idx = this->findKitchen();
      if (idx == -1)
	{
	  this->createKitchen();
	  --i;
	}
      else
	this->pipe[idx]->first->put(lines[i]);
    }
}

void	Reception::run()
{
  bool	done = false;

  createKitchen();
  while (!done)
    {
      this->dispatch(this->getCmdLine());
    }
}
