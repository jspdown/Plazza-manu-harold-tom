#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "NamedPipe.hh"

NamedPipe::NamedPipe(const std::string &name)
  : name(name)
{
  if (mkfifo(name.c_str(), S_IRWXU) < 0)
    throw NamedPipe::NamedPipeError(); //warning
  this->file.open(name.c_str(), std::fstream::in | std::fstream::out | std::fstream::trunc);
}

NamedPipe::~NamedPipe()
{
}

std::string	NamedPipe::get()
{
  std::string	msg;

  std::getline(this->file, msg);
  return msg;
}

void	NamedPipe::put(const std::string &msg)
{
  file << msg;
}

const char * NamedPipe::NamedPipeError::what() const throw()
{
  return ("[Error]:\tNamed Error\n");
}
