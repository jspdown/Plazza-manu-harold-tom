
#include	<iostream>
#include	<sstream>
#include	"Convert.hh"
#include	"CmdLineParse.hh"

void		CmdLineParse::sepTrame(std::vector<std::string> &r, const std::string &line)
{
  size_t	nbr;
  std::string	mul;

  size_t pos = line.rfind(":");
  if (pos != std::string::npos)
    {
      mul = line.substr(pos + 1);
      size_t m = mul.find("x");
      if (m != std::string::npos)
	{
	  std::string	n = mul.substr(m + 1);
	  nbr = Convert::stringToInt(n);
	  for (size_t i = 0; i < nbr; ++i)
	    r.push_back(line.substr(0, pos));
	}
      else
	throw SyntaxError::SyntaxError;
    }
  else
    throw SyntaxError::SyntaxError;
}

std::string	CmdLineParse::toTrame(const std::string &in)
{
  std::stringstream	ss(in);
  std::string		cmd("GetPizza");
  std::string		buff;
  std::string		res("");
  size_t       		size;

  while (ss.good())
    {
      size = res.size() - 1;
      ss >> buff;
      res.append(buff);
      res.append(":");
    }
  res.erase(res.size() - 1);
  std::cout << "[toTrame res] : " << res << std::endl;
  cmd.append("[");
  cmd.append(Convert::intToString(size));
  cmd.append("]:");
  cmd.append(res);
  std::cout << "[toTrame] : " << cmd << std::endl;
  return (cmd);
}

std::vector<std::string>	CmdLineParse::CmdLineToTrame(const std::string &in)
{
  std::string	tmp(in);
  size_t	dot;
  std::string	line;
  std::vector<std::string>	res;

  while ((dot = tmp.find(";")) != std::string::npos)
    {
      std::cout << tmp.substr(0, dot) << std::endl;
      line = toTrame(tmp.substr(0, dot));
      sepTrame(res, line);
      tmp = tmp.substr(dot + 1);
    }
  std::cout << tmp << std::endl;
  line = toTrame(tmp);
  sepTrame(res, line);
  return (res);
}

SyntaxError::SyntaxError()
{
  
}
SyntaxError::~SyntaxError()
{

}
const char* SyntaxError::what() const throw()
{
  return ("[Error] : \tSyntax Error");
}
