#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "NamedPipe.hh"

NamedPipe::NamedPipe(const std::string &name)
  : name(name)
{
  std::cout << name << std::endl;
  if (mkfifo(name.c_str(), S_IRWXU) < 0)
    throw NamedPipe::NamedPipeError(); //warning
  this->file.open(name.c_str(), std::fstream::in | std::fstream::out | std::fstream::trunc);
  if (!this->file.good())
    throw NamedPipe::NamedPipeError();
  this->file << "lalal" << std::endl;
}

NamedPipe::~NamedPipe()
{
}

std::string	NamedPipe::get()
{
  std::string	msg;

  std::getline(this->file, msg);
  if (!this->file.good())
    throw NamedPipe::NamedPipeError();
  return msg;
}

void	NamedPipe::put(const std::string &msg)
{
  this->file << msg;
  if (!this->file.good())
    throw NamedPipe::NamedPipeError();
}

const char * NamedPipe::NamedPipeError::what() const throw()
{
  return ("[Error]:\tNamed Error\n");
}
