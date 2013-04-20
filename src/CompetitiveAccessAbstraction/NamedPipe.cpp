#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "NamedPipe.hh"

NamedPipe::NamedPipe(std::string name)
  : name(name)
{
  if (mkfifo(name.c_str(), S_IRWXU) < 0)
    throw std::exception;
  this->file.open(name.c_str(), std::fstream::in | std::fstream::out | std::fstream::trunc);
}

NamedPipe::~NamedPipe()
{
  close(this->fd);
}

std::string	NamedPipe::get()
{
  std::string	msg;

  std::getline(this->file, msg);
  return msg;
}

void	NamedPipe::put(std::string msg)
{
  file << msg;
}
