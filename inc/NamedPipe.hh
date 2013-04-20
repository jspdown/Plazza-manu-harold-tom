#ifndef __NAMED_PIPE_HPP__
#define __NAMED_PIPE_HPP__

#include <string>
#include <fstream>
#include <vector>

class NamedPipe
{
private:
  std::string	name;
  int		fd;
  std::fstream	file;

public:
  class NamedPipeError :public std::exception
  {
    const char * what() const throw();
  };
	       	NamedPipe(const std::string &);
      		~NamedPipe();
  std::string	get();
  void	       	put(const std::string &);
  int		getFd()	const;
};

#endif // __NAMED_PIPE_HPP__
