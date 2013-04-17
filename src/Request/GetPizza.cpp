
#include	"GetPizza.hh"
#include	"Convert.hh"


GetPizza::GetPizza(TypePizza id, TaillePizza size) :
  ARequest("GetPizza"), id(id), size(size)
{

}

GetPizza::~GetPizza()
{

}

ARequest			*GetPizza::clone()	const
{
  return (new GetPizza(this->id, this->size));
}
std::string			GetPizza::pack()		const
{
  std::string	serialized("GetPizza");
  serialized.append(":");
  serialized.append(Convert::TypePizzaToString(this->id));
  serialized.append(":");
  serialized.append(Convert::TaillePizzaToString(this->size));
  return (serialized);
}

TypePizza	GetPizza::getId()		const
{
  return (this->id);
}
TaillePizza	GetPizza::getSize()	const
{
  return (this->size);
}
void	GetPizza::setId(TypePizza i)
{
  this->id = i;
}
void	GetPizza::getSize(TaillePizza s)
{
  this->size = s;
}
