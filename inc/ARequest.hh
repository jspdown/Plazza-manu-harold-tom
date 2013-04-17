
#ifndef		__AREQUEST_HH__
# define	__AREQUEST_HH__

#include	<vector>
#include	<string>
#include	"ITrame.hh"

class	ARequest: public	ITrame
{
  std::string	name;
public:
  ARequest(const std::string &name);
  virtual ~ARequest();
  ARequest(const ARequest &);
  ARequest	&operator=(const ARequest &);

  virtual ARequest			*clone()				const = 0;
  virtual std::vector<std::string>	unpack(const std::string &trame)	const;
  std::string	getName() const;
  void	setName(const std::string &name);
};

#endif
