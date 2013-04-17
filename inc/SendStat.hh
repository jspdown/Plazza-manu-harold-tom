
#ifndef		__SENDSTAT_HH__
# define	__SENDSTAT_HH__

#include	<map>
#include	<utility>
#include	<string>
#include	"ARequest.hh"
#include	"Pizza.hh"

class	SendStat: public	ARequest
{
  int							nbr_free_cooks;
  int							nbr_occuped_cooks;
  int							nbr_pizza_possible;
  std::map<std::pair<TypePizza, TaillePizza>, int>	pizza;
  std::map<TypeIngredient, int>				ingredient;

public:
  SendStat(int nfc,
	   int noc, 
	   int npp, 
	   std::map<std::pair<TypePizza, TaillePizza>, int> pizza,
	   std::map<TypeIngredient, int> ingr);
  virtual ~SendStat();
  SendStat(const SendStat&);
  SendStat	&operator=(const SendStat &);

  virtual SendStat			*clone()	const;
  virtual std::string			pack()		const;

  int	getNbrFreeCooks()	const;
  int	getNbrOccupedCooks()	const;
  int	getNbrPizzaCooks()	const;
  std::map<std::pair<TypePizza, TaillePizza>, int>	getPizza()	const;
  std::map<TypeIngredient, int>				getIngredient()	const;

  void	getNbrFreeCooks(int nfc);
  void	getNbrOccupedCooks(int noc);
  void	getNbrPizzaCooks(int npc);
  void	getPizza(std::map<std::pair<TypePizza, TaillePizza>, int> p);
  void	getIngredient(std::map<TypeIngredient, int> i);
};

#endif
