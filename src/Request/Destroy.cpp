
#include	"Destroy.hh"


Destroy::Destroy() :
  ARequest("Destroy")
{

}

Destroy::~Destroy()
{

}

Destroy			*Destroy::clone()	const
{
  return (new Destroy());
}

std::string		        Destroy::pack()		const
{
  std::string	serialized("Destroy");
  return (serialized);
}

