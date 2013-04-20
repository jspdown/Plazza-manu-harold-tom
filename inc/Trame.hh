
#ifndef		__TRAME_HH__
# define	__TRAME_HH__

#include	<vector>
#include	<string>

class	Trame
{
public:
  static std::string			pack(const std::string &cmd, std::vector<std::string> elms);
  static std::vector<std::string>	unpack(const std::string &tr);

  static std::string			group(std::vector<std::string> entry, const std::string &delim);
  static std::vector<std::string>	cut(const std::string &sub, const std::string &delim);
  static std::string			getCmd(const std::string &tr);
  static std::string			getCmd(std::vector<std::string> l);
  static int				getSize(const std::string &tr);
  static int				getSize(std::vector<std::string> l);
};

#endif
