#ifndef __NAMED_PIPE_HPP__
#define __NAMED_PIPE_HPP__

#include <string>
#include <fstream>
#include <vector>

#define	READ_SIZE	(((512 * 12 + 8) / 2 - 1080 * 2 - 512) / 2 - 201)

class NamedPipe
{
private:
  int			fd;
  const std::string	name;

public:
  class NamedPipeError :public std::exception
  {
    const char * what() const throw();
  };
	       	NamedPipe(const std::string &);
	       	NamedPipe(int);
      		~NamedPipe();
  std::string	get();
  void	       	put(const std::string &);
  int		getFd()	const;

  NamedPipe	&operator<<(const std::string &trame);
  NamedPipe	&operator>>(std::string &trame);

};



#endif // __NAMED_PIPE_HPP__
