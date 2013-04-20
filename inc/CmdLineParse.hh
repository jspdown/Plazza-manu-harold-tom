
#ifndef		__CMDLINEPARSE_HH__
# define	__CMDLINEPARSE_HH__

#include	<exception>
#include	<string>
#include	<vector>


class	CmdLineParse
{
public:
  class	SyntaxError: public std::exception
  {
  public:
    virtual const char* what() const throw();
  };
  static void			       	sepTrame(std::vector<std::string> &r, const std::string &line);
  static std::string			toTrame(const std::string &in);
  static std::vector<std::string>	CmdLineToTrame(const std::string &in);
};

#endif
