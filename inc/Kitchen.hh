
#ifndef		__KITCHEN_HH__
# define	__KITCHEN_HH__

#include	<map>
#include	<utility>
#include	<exception>
#include	"Pizza.hh"
#include	"UnixMutex.hh"
#include	"UnixThread.hh"
#include	"NamedPipe.hh"

class	Manager;


class	Kitchen
{
public:
static UnixMutex     				*c_mutex;
static int					c_id;
private:
  int						kitchen_id;
  int						nbr_cooks;
  UnixThread					*thread_counter;
  Manager					*chief;
  UnixThread					thread_sender;
public:
  Kitchen(int nbr_cooks, int fd_in, int fd_out, int num);
  ~Kitchen();
  Kitchen(const Kitchen &other);
  std::pair<NamedPipe, NamedPipe>		pipe;
  std::map<TypeIngredient, int>	ingredients;
  Kitchen	&operator=(const Kitchen &other);

  void	close();
  std::string	getOrder();
  void		sendOrder(const std::string &);
  std::map<TypeIngredient, int>	getIngredients()	const;
  void		incressIngredients();
  bool		canCookPizza(Pizza *p);
  std::string	buildStat();
  void		run();
  void		log(const std::string &msg);
  int		getNbrPizzaPossible();
  Manager	*getChief();
  void		throwCounter();

  class	KitchenError: public std::exception
  {
const char *what()	const throw();
  };
};

#endif
