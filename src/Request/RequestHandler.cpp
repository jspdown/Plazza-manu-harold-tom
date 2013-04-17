
#include	"RequestHandler.hh"
#include	"SendStat.hh"
#include	"GetStat.hh"
#include	"GetPizza.hh"
#include	"SendPizza.hh"
#include	"Destroy.hh"
#include	"Pizza.hh"

RequestHandler::RequestHandler()
{
  std::map<std::pair<TypePizza, TaillePizza>, int>	pp;
  std::map<TypeIngredient, int>				pi;

  pp[std::pair<TypePizza, TaillePizza>(Margarita, XL)] = 2;
  pp[std::pair<TypePizza, TaillePizza>(Margarita, S)] = 8;
  pp[std::pair<TypePizza, TaillePizza>(Americaine, L)] = 2;

  pi[Doe] = 1;
  pi[Eggplant] = 5;
  pi[Gruyere] = 1;
  pi[Ham] = 9;

  
  this->requests["SendPizza"] = new SendPizza(Margarita, XL);
  this->requests["SendStat"] = new SendStat(2, 1, 3, pp, pi);
  this->requests["GetPizza"] = new GetPizza(Margarita, XL);
  this->requests["GetStat"] = new GetStat();
  this->requests["Destroy"] = new Destroy();
}

RequestHandler::~RequestHandler()
{

}

ARequest	*RequestHandler::build(const std::string &name)	const
{
  std::map<std::string, ARequest *>::const_iterator	it = this->requests.find(name);

  if (it == this->requests.end())
    return (0);
  return (it->second->clone());
}

void	RequestHandler::learn(ARequest *n)
{
  std::map<std::string, ARequest *>::const_iterator	it = this->requests.find(n->getName());

  if (it == this->requests.end())
    this->requests[n->getName()] = n->clone();
}

void	RequestHandler::unlearn(const std::string &name)
{
    std::map<std::string, ARequest *>::iterator	it = this->requests.find(name);

    if (it != this->requests.end())
      this->requests.erase(it);
}
