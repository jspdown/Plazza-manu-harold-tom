
#include	<iostream>
#include	"RequestHandler.hh"
#include	"Destroy.hh"
#include	"SendStat.hh"
#include	"SendPizza.hh"
#include	"GetPizza.hh"
#include	"GetStat.hh"

int	main()
{
  std::cout << "[TEST REQUESTHANDLER]" << std::endl;
  RequestHandler	rh;
  ARequest		*ss;
  ARequest		*sp;
  ARequest		*gp;
  ARequest  		*gs;
  ARequest		*d;

  std::cout << "[building]" << std::endl;
  ss = rh.build("SendStat");
  sp = rh.build("SendPizza");
  gp = rh.build("GetPizza");
  gs = rh.build("GetStat");
  d = rh.build("Destroy");
  std::cout << "[pack]" << std::endl;
  std::cout << ss->pack() << std::endl;
  std::cout << sp->pack() << std::endl;
  std::cout << gp->pack() << std::endl;
  std::cout << gs->pack() << std::endl;
  std::cout << d->pack() << std::endl;
  std::cout << "[end]" << std::endl;
  return (0);
}

