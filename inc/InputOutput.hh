#ifndef __INPUT_OUTPUT_HH__
#define __INPUT_OUTPUT_HH__

#include	<istream>
#include	<ostream>

class InputOutput
{
private:
  std::istream &	in;
  std::ostream &	out;

public:
			InputOutput();
			~InputOutput();
  const std::string &	read();
  void			write(const std::string &);
};

#endif // __INPUT_OUTPUT_HH__
