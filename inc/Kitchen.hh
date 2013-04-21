
#ifndef		__KITCHEN_HH__
# define	__KITCHEN_HH__

#include	<map>
#include	<utility>
#include	<fstream>
#include	<exception>
#include	"Pizza.hh"
#include	"UnixMutex.hh"
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
  std::pair<NamedPipe *, NamedPipe *>		pipe;
  Manager					*chief;
  std::ofstream					log_file;
  std::map<TypeIngredient, int>	ingredients;
public:
  Kitchen(int nbr_cooks, NamedPipe *in, NamedPipe *out);
  ~Kitchen();
  Kitchen(const Kitchen &other);
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
  class	KitchenError: public std::exception
  {
const char *what()	const throw();
  };
};

#endif
