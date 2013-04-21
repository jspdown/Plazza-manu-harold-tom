#include	"InputOutput.hh"

#include	<iostream>

InputOutput::InputOutput()
  : in(std::cin),
    out(std::cout)
{
}

InputOutput::~InputOutput()
{
}

std::string	InputOutput::read()
{
  std::string	msg;

  std::getline(this->in, msg);
  return msg;
}

void			InputOutput::write(const std::string & msg)
{
  this->out << msg;
}
