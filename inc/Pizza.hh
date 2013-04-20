
#ifndef		__PIZZA_HH__
# define	__PIZZA_HH__

#include	<string>
#include	<map>

enum	TypePizza
  {
    Americana = 1,
    Fantasia = 2,
    Margarita = 4,
    Regina = 8
  };

enum	TaillePizza
  {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
  };

enum	TypeIngredient
  {
    Doe	= 1,
    Eggplant = 2,
    Goat_cheese = 4,
    Gruyere = 8,
    Ham = 16,
    Mushroom = 32,
    Steak = 64,
    Tomato = 128,
    ChiefLove = 254
  };

class	Pizza
{
  TypePizza			id;
  std::string			name;
  TaillePizza			size;
  std::map<TypeIngredient, int>	recipe;

public:
  Pizza(TypePizza id, const std::string &name, TaillePizza size, std::map<TypeIngredient, int> recipe);
  ~Pizza();
  Pizza(const Pizza &);
  Pizza &operator=(const Pizza &);

  Pizza	*clone();
  
  std::string			getName()	const;
  std::string			getSizeText()	const;
  TaillePizza			getSize()	const;
  std::map<TypeIngredient, int> getRecipe()	const;

  void	setName(const std::string &name);
  void	setSize(TaillePizza size);
  void	setRecipe(std::map<TypeIngredient, int> recipe);
  void	setId(TypePizza id);
};

#endif
