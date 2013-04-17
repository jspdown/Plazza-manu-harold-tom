
#ifndef		__REQUESTHANDLER_HH__
# define	__REQUESTHANDLER_HH__

#include	<map>
#include	<string>
#include	"ARequest.hh"

class	RequestHandler
{
  std::map<std::string, ARequest *>	requests;
public:
  RequestHandler();
  ~RequestHandler();
  RequestHandler(const RequestHandler &);
  RequestHandler &operator=(const RequestHandler &);

  ARequest	*build(const std::string &name)	const;
  void		learn(ARequest *n);
  void		unlearn(const std::string &name);
};
#endif
