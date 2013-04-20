#ifndef __RECEPTION_HH__
#define __RECEPTION_HH__

#include	<deque>
#include	<utility>

#include	"IProcess.hh"
//#include	"InputOutput.hh"
#include	"NamedPipe.hh"
#include	"Pizza.hh"

class Reception
{
private:
  IProcess						*process;
  int							nbr_cooks;
  //  InputOutput						io;
  std::deque<std::pair<NamedPipe *, NamedPipe *> >	pipe;
  std::deque<IProcess *>				processes;

public:
	Reception(int nbr_cooks);
	~Reception();
  void	createKitchen();
  void	deliverPizza(Pizza *) const;
  void	run();
  void	destroyKitchen(int);
  void	getOrder();
  int	checkStatus() const;
};

#endif // __RECEPTION_HH__
