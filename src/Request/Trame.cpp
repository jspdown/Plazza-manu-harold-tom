#include	<iostream>
#include	"Convert.hh"
#include	"Trame.hh"

std::vector<std::string>	Trame::cut(const std::string &sub, const std::string &delim)
{
  size_t			pos;
  std::string			op(sub);
  std::vector<std::string>	res;

  while ((pos = op.find(delim)) != std::string::npos)
    {
      res.push_back(op.substr(0, pos));
      op = op.substr(pos + 1);
    }
  res.push_back(op);
  return (res);
}

std::string	Trame::group(std::vector<std::string> entry, const std::string &delim)
{
  std::string	res("");

  for (unsigned int i = 0; i < entry.size(); ++i)
    {
      res.append(entry[i]);
      if (i != entry.size() - 1)
	res.append(delim);
    }
  return (res);
}



std::string			Trame::pack(const std::string &cmd, std::vector<std::string> elms)
{
  std::string	res(cmd);
  std::string	tmp("");

  tmp.append(group(elms, ":"));
  res.append("[");
  res.append(Convert::intToString(tmp.size()));
  res.append("]:");
  res.append(tmp);
  return (res);
}

std::vector<std::string>	Trame::unpack(const std::string &tr)
{
  std::string	tmp;

  return (cut(tr, ":"));
}

std::string	Trame::getCmd(const std::string &tr)
{
  size_t	pos;

  pos = tr.find("[");
  if (pos != std::string::npos)
    return (tr.substr(0, pos));
  return (std::string(""));
}

std::string	Trame::getCmd(std::vector<std::string> l)
{
  if (l.size() > 0)
    return (getCmd(l[0]));
  return (std::string(""));
}

int	Trame::getSize(const std::string &tr)
{
  size_t	pos;
  size_t	pos2;

  pos = tr.find("[");
  pos2 = tr.find("]");
  if (pos != std::string::npos && pos2 != std::string::npos && pos2 > pos)
    return (Convert::stringToInt(tr.substr(pos, pos2)));
  return (0);
}

int	Trame::getSize(std::vector<std::string> l)
{
  if (l.size() > 0)
    return (getSize(l[0]));
  return (0);
}
