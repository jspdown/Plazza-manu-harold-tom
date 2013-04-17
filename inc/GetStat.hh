
#ifndef		__GETSTAT_HH__
# define	__GETSTAT_HH__

#include	<string>
#include	"ARequest.hh"

class	GetStat: public	ARequest
{
public:
  GetStat();
  virtual ~GetStat();
  GetStat(const GetStat&);
  GetStat	&operator=(const GetStat &);

  virtual ARequest			*clone()	const;
  virtual std::string			pack()		const;
};

#endif
