#ifndef __I_OUTPUT_HH__
#define __I_OUTPUT_HH__

#include <string>

class IOutput
{
protected:
  virtual std::string &	read() = 0;
};

#endif // __I_OUTPUT_HH__
