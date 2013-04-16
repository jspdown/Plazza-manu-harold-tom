
#include	<iostream>
#include	"PizzaHandler.hh"
#include	"Pizza.hh"

int	main()
{
  PizzaHandler	handle;

  handle.build(std::string("Americaine"), XL);
  handle.build(std::string("Americaine"), L);
  handle.build(std::string("Fantasia"), S);
  handle.build(std::string("lol"), S);
  return (0);
}
