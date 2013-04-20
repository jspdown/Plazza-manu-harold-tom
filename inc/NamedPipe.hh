#ifndef __NAMED_PIPE_HPP__
#define __NAMED_PIPE_HPP__

#include <string>
#include <fstream>
#include <vector>

class NamedPipe
{
private:
  std::string	name;
  std::fstream	file;

public:
	       	NamedPipe(std::string);
      		~NamedPipe();
  std::string	get();
  void	       	put(std::string);
};

#endif // __NAMED_PIPE_HPP__
