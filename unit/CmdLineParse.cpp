
#include	<vector>
#include	<string>
#include	<iostream>
#include	"CmdLineParse.hh"

int	main(int ac, char **av)
{
  if (ac != 2)
    return (1);
  std::vector<std::string>	res;
  std::string			in(av[1]);

  std::cout << "[begin]:\t" << in << std::endl;
  res = CmdLineParse::CmdLineToTrame(in);
  for (unsigned int i = 0; i < res.size(); ++i)
    std::cout << "[" << res[i] << "]" << std::endl;
  return (0);
}
