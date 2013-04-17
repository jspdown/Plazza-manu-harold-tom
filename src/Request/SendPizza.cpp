
#include	"SendPizza.hh"
#include	"Convert.hh"


SendPizza::SendPizza(TypePizza id, TaillePizza size) :
  ARequest("SendPizza"), id(id), size(size)
{

}

SendPizza::~SendPizza()
{

}

ARequest			*SendPizza::clone()	const
{
  return (new SendPizza(this->id, this->size));
}
std::string			SendPizza::pack()		const
{
  std::string	serialized("SendPizza");
  serialized.append(":");
  serialized.append(Convert::TypePizzaToString(this->id));
  serialized.append(":");
  serialized.append(Convert::TaillePizzaToString(this->size));
  return (serialized);
}

void	SendPizza::setId(TypePizza id)
{
  this->id = id;
}
void	SendPizza::setSize(TaillePizza size)
{
  this->size = size;
}
TypePizza	SendPizza::getId()		const
{
  return (this->id);
}
TaillePizza	SendPizza::getSize()	const
{
  return (this->size);
}
