
#include	<iostream>
#include	"Convert.hh"
#include	"SendStat.hh"

SendStat::SendStat(int nfc,
	 int noc, 
	 int npp, 
	 std::map<std::pair<TypePizza, TaillePizza>, int> pizza,
	 std::map<TypeIngredient, int> ingr) :
  ARequest("SendStat"), nbr_free_cooks(nfc), nbr_occuped_cooks(noc), nbr_pizza_possible(npp), pizza(pizza), ingredient(ingr)
{

}

SendStat::~SendStat()
{

}

SendStat			*SendStat::clone()	const
{
  return (new SendStat(this->nbr_free_cooks, 
		       this->nbr_occuped_cooks, 
		       this->nbr_pizza_possible,
		       this->pizza,
		       this->ingredient));
}
std::string			SendStat::pack()		const
{
  std::string	serialized("SendStat");
  serialized.append(":");
  serialized.append(Convert::intToString(this->nbr_free_cooks));
  serialized.append(":");
  serialized.append(Convert::intToString(this->nbr_occuped_cooks));
  serialized.append(":");
  serialized.append(Convert::intToString(this->nbr_pizza_possible));
  serialized.append(":");
  for (std::map<std::pair<TypePizza, TaillePizza>, int>::const_iterator it = this->pizza.begin(); 
	 it != this->pizza.end(); 
	 ++it)
    {
      serialized.append(Convert::TypePizzaToString(it->first.first));
      serialized.append("-");
      serialized.append(Convert::TaillePizzaToString(it->first.second));
      serialized.append("-");
      serialized.append(Convert::intToString(it->second));
      serialized.append("|");
    }
  serialized.append(":");
  for (std::map<TypeIngredient, int>::const_iterator it = this->ingredient.begin(); it != this->ingredient.end(); ++it)
    {
      serialized.append(Convert::TypeIngredientToString(it->first));
      serialized.append("+");
      serialized.append(Convert::intToString(it->second));
      serialized.append("/");
    }
  return (serialized);
}

int	SendStat::getNbrFreeCooks()	const
{
  return (this->nbr_free_cooks);
}
int	SendStat::getNbrOccupedCooks()	const
{
  return (this->nbr_occuped_cooks);
}
int	SendStat::getNbrPizzaCooks()	const
{
  return (this->nbr_pizza_possible);
}
std::map<std::pair<TypePizza, TaillePizza>, int>	SendStat::getPizza()	const
{
  return (this->pizza);
}
std::map<TypeIngredient, int>				SendStat::getIngredient()	const
{
  return (this->ingredient);
}

void	SendStat::getNbrFreeCooks(int nfc)
{
  this->nbr_free_cooks = nfc;
}
void	SendStat::getNbrOccupedCooks(int noc)
{
  this->nbr_occuped_cooks = noc;
}
void	SendStat::getNbrPizzaCooks(int npc)
{
  this->nbr_pizza_possible = npc;
}
void	SendStat::getPizza(std::map<std::pair<TypePizza, TaillePizza>, int> p)
{
  this->pizza = p;
}
void	SendStat::getIngredient(std::map<TypeIngredient, int> i)
{
  this->ingredient = i;
}
