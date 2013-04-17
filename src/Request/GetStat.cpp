
#include	"GetStat.hh"


GetStat::GetStat() :
  ARequest("GetStat")
{

}

GetStat::~GetStat()
{

}

ARequest			*GetStat::clone()	const
{
  return (new GetStat());
}

std::string			GetStat::pack()		const
{
  std::string	serialized("GetStat");
  return (serialized);
}

