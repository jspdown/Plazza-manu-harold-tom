
#ifndef		__TRAME_HH__
# define	__TRAME_HH__

#include	<vector>
#include	<string>

class	Trame
{
public:
  static std::string			pack(const std::string &cmd, std::vector<std::string> elms);
  static std::vector<std::string>	unpack(const std::string &tr);

  static std::vector<std::string>	cut(const std::string &sub, const std::string &delim);
  static std::string			Trame::getCmd(const std::string &tr);
  static std::string			Trame::getCmd(std::vector<std::string> l);
  static int				Trame::getSize(const std::string &tr);
  static int				Trame::getSize(std::vector<std::string> l);
};

#endif
