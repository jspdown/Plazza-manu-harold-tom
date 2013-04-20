
#include	"Trame.hh"

std::vector<std::string>	Trame::cut(const std::string &sub, const std::string &delim)
{
  unsigned int			pos;
  std::string			op(sub);
  std::vector<std::string>	res;

  while ((pos = op.find(delim)) != std::string::npos)
    {
      res.pushback(op.substr(0, pos));
      op = op.substr(pos);
    }
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



std::string			Trame::pack(std::string cmd, std::vector<std::string> elms)
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

sotd::vector<std::string>	Trame::unpack(const std::string &tr)
{
  std::string	tmp;
  unsigned int	pos;

  pos = tr.find
  return (cut(tr, ":"));
}

std::string	Trame::getCmd(const std::string &tr)
{
  unsigned int	pos;

  pos = tr.find("[");
  if (pos != std::string::npos)
    return (tr.substr(0, pos));
}

std::string	Trame::getCmd(std::vector<std::string> l)
{
  if (l.size > 0)
    return (getCmd(l[0]));
}

int	Trame::getSize(const std::string &tr)
{
  unsigned int	pos;
  unsigned int	pos2;

  pos = tr.find("[");
  pos2 = tr.find("]");
  if (pos != std::string::npos && pos2 != std::string::npos && pos2 > pos)
    return (Convert::stringToInt(tr.substr(pos, pos2)));
}

int	Trame::getSize(std::vector<std::string> l)
{
  if (l.size > 0)
    return (getSize(l[0]));
}
