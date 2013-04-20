#ifndef __RECEPTION_HH__
#define __RECEPTION_HH__

#include <deque>
#include <utility>

#include "IProcess.hh"
//#include "InputOutput.hh"
#include "NamedPipe.hh"
#include "Pizza.hh"

class Reception
{
private:
  IProcess					*process;
  //  InputOutput					io;
  std::deque<std::pair<NamedPipe, NamedPipe> >	pipe;
  std::deque<IProcess *>			processes;

public:
	Reception();
	~Reception();
  void	createKitchen();
  void	deliverPizza(Pizza *);
  void	run();
  void	destroyKitchen(int);
  void	transferOrder();
  int	checkStatus();
};

#endif // __RECEPTION_HH__