
#include	"Kitchen.hh"

Kitchen::Kitchen(NamedPipe *in, NamedPipe *out) :
  pipe(std::pair<NamedPipe *, NamedPipe *>(in, out))
  
{
  
}

Kitchen::~Kitchen()
{

}

void	Kitchen::close()
{
  std::cout << "close" << std::endl;
}

void	Kitchen::checkOrder()
{
  for (unsigned int i = 0; i < 5 ; ++i)
    this->chief.preparePizza("lol");
}

void	Kitchen::sendOrder(const std::string &str)
{
  std::cout << "send order [" << str << "]" << std::endl;
}

std::map<std::pair<TypeIngredient, int> >	getIngredients()	const
{
  return (this->ingredients);
}
