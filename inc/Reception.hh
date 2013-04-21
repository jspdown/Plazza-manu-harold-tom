#ifndef __RECEPTION_HH__
#define __RECEPTION_HH__

#include	<deque>
#include	<utility>
#include	<fstream>
#include	"IProcess.hh"
#include	"InputOutput.hh"
#include	"NamedPipe.hh"
#include	"Kitchen.hh"
#include	"UnixThread.hh"
#include	"Pizza.hh"

class Reception
{
private:
  UnixThread						delivery_man;
  UnixThread						*reader;
  IProcess						*process;
  int							nbr_cooks;
  InputOutput						io;
  std::deque<std::pair<NamedPipe *, NamedPipe *> *>	pipe;
  std::deque<std::string>      				ressources;

public:
	Reception(int nbr_cooks);
	~Reception();
  void	fillRessources();
  void	applyOutput();
  void	createKitchen();
  std::vector<std::string>	getCmdLine();
  std::string	searchTrame(const std::string &seek);
  int		findKitchen();
  void		dispatch(std::vector<std::string> lines);
  void		throwReader();
  void		run();

  void		lockWriter();
  void		unlockWriter();
};

void	*delivery(void *data);

#endif // __RECEPTION_HH__
