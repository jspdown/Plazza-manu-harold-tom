
#ifndef		__DESTROY_HH__
# define	__DESTROY_HH__

#include	<string>
#include	"ARequest.hh"

class	Destroy: public	ARequest
{
public:
  Destroy();
  virtual ~Destroy();
  Destroy(const Destroy&);
  Destroy	&operator=(const Destroy &);

  virtual Destroy			*clone()	const;
  virtual std::string			pack()		const;
};

#endif
