
#ifndef		__ITRAME_HH__
# define	__ITRAME_HH__

#include	<string>

class	ITrame
{
public:
  virtual std::string			pack() 	const = 0;
  virtual std::vector<std::string>	unpack(const std::string &trame)	const = 0;
};

#endif
