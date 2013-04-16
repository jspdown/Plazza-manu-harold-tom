#ifndef __NAMED_PIPE_HPP__
#define __NAMED_PIPE_HPP__

#include <string>

#include "Trame.hpp"

class NamedPipe
{
private:
  std::string	name;

public:
		NamedPipe();
		~NamedPipe();
  Trame *	get();
  void		put(Trame *);
};

#endif // __NAMED_PIPE_HPP__
