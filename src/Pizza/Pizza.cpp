
#include	"Pizza.hh"

Pizza::Pizza(TypePizza id, const std::string &name, TaillePizza size, std::map<TypeIngredient, int> recipe) :
  id(id), name(name), size(size), recipe(recipe)
{
  
}

Pizza::~Pizza()
{

}

Pizza	*Pizza::clone()
{
  return (new Pizza(this->id, this->name, this->size, this->recipe));
}


std::string			Pizza::getName()	const
{
  return (this->name);
}
std::string			Pizza::getSizeText()	const
{
  std::map<TaillePizza, std::string> in;

  in[S] = std::string("S");
  in[M] = std::string("M");
  in[L] = std::string("L");
  in[XL] = std::string("XL");
  in[XXL] = std::string("XXL");
  std::map<TaillePizza, std::string>::iterator	it;

  
  it = in.find(this->size);
  if (it == in.end())
    return (std::string(""));
  return (it->second);
}
TaillePizza			Pizza::getSize()	const
{
  return (this->size);
}
std::map<TypeIngredient, int>	Pizza::getRecipe()	const
{
  return (this->recipe);
}

void	Pizza::setName(const std::string &name)
{
  this->name = name;
}
void	Pizza::setSize(TaillePizza size)
{
  this->size = size;
}
void	Pizza::setRecipe(std::map<TypeIngredient, int> recipe)
{
  this->recipe = recipe;
}
void	Pizza::setId(TypePizza id)
{
  this->id = id;
}
