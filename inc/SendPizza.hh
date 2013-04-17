
#ifndef		__SENDPIZZA_HH__
# define	__SENDPIZZA_HH__

#include	<vector>
#include	<string>
#include	"ARequest.hh"
#include	"Pizza.hh"

class	SendPizza: public	ARequest
{
  TypePizza	id;
  TaillePizza	size;
public:
  SendPizza(TypePizza id, TaillePizza size);
  ~SendPizza();
  SendPizza(const SendPizza&);
  SendPizza	&operator=(const SendPizza &);

  ARequest			*clone()	const;
  std::string			pack()		const;

  void	setId(TypePizza id);
  void	setSize(TaillePizza size);
  TypePizza	getId()		const;
  TaillePizza	getSize()	const;
};

#endif
