#ifndef __I_INPUT_HH__
#define __I_INPUT_HH__

#include <string>

class IInput
{
protected:
  virtual void	write(const std::string &) = 0;
};

#endif // __I_INPUT_HH__
