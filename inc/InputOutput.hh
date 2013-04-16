#ifndef __INPUT_OUTPUT_HH__
#define __INPUT_OUTPUT_HH__

#include "IInput.hh"
#include "IOutput.hh"

class InputOutput
{
private:
  IInput *	in;
  IOutput *	out;

public:
  std::string &	read();
  void		write(const std::string &);
};

#endif // __INPUT_OUTPUT_HH__
