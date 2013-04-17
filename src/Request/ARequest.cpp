
#include	"ARequest.hh"

ARequest::ARequest(const std::string &name) :
  name(name)
{
  
}

ARequest::~ARequest()
{

}

std::vector<std::string>	ARequest::unpack(const std::string &trame)	const
{
  std::string			tmp(trame);
  size_t			pos;
  std::vector<std::string>	res;
  
  while ((pos = tmp.find(":")) != std::string::npos)
    {
      res.push_back(tmp.substr(0, pos));
      tmp = tmp.substr(pos);
    }
  return (res);
}

std::string	ARequest::getName() const
{
  return (this->name);
}
void	ARequest::setName(const std::string &name)
{
  this->name = name;
}
