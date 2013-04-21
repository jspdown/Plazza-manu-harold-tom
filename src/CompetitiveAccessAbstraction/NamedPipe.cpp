
#include <sys/select.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <string.h>
#include <errno.h>

#include "NamedPipe.hh"

NamedPipe::NamedPipe(const std::string &name)
{
  std::cout << name << std::endl;
  if (mkfifo(name.c_str(), S_IRWXU) < 0)
    {
      std::cout << "error fifo" << std::endl;
      perror(strerror(errno));
      throw NamedPipe::NamedPipeError();
    }
  this->fd = open(name.c_str(), O_RDWR | O_CREAT);
  if (this->fd < 0)
    {
      std::cout << "error file not found" << std::endl;
      throw NamedPipe::NamedPipeError();
    }
}
NamedPipe::NamedPipe(int fd) :
  fd(fd)
{

}

NamedPipe::~NamedPipe()
{
}


std::string	NamedPipe::get()
{
  char	buff[READ_SIZE + 1];
  int	size;
  bool	done = false;
  std::string	line("");
  
  while (!done && (size = read(this->fd, buff, READ_SIZE)) > 0)
    {
      if (buff[0] == '\n')
	done = true;
      else
	line.push_back(buff[0]);
    }
  return (line);
}

void	NamedPipe::put(const std::string &msg)
{
  const char	*buff;

  buff = msg.c_str();
  write(this->fd, buff, strlen(buff));
  write(this->fd, "\n", 1);
}

int	NamedPipe::getFd() const
{
  return (this->fd);
}

NamedPipe	&NamedPipe::operator<<(const std::string &trame)
{
  this->put(trame);
  return (*this);
}
NamedPipe	&NamedPipe::operator>>(std::string &trame)
{
  trame = this->get();
  return (*this);
}


const char * NamedPipe::NamedPipeError::what() const throw()
{
  return ("[Error]:\tNamed Error\n");
}

