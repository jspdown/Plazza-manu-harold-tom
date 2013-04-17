
#ifndef		__GETPIZZA_HH__
# define	__GETPIZZA_HH__

#include	<string>
#include	"ARequest.hh"
#include	"Pizza.hh"

class	GetPizza: public	ARequest
{
  TypePizza	id;
  TaillePizza	size;

public:
  GetPizza(TypePizza id, TaillePizza size);
  ~GetPizza();
  GetPizza(const GetPizza&);
  GetPizza	&operator=(const GetPizza &);

  ARequest			*clone()	const;
  std::string			pack()		const;

  TypePizza	getId()		const;
  TaillePizza	getSize()	const;
  void	setId(TypePizza i);
  void	getSize(TaillePizza s);
};

#endif
