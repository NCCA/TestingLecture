#include <string>
#include <iostream>

bool stringToDouble(const std::string &_str, double &io_result)
{
	bool success=true;

  try
	{
    io_result = std::stod(_str);
    //std::cerr<<_str<<' '<<io_result<<'\n';
  }
	catch(std::invalid_argument)
	{
    success=false;
	}

	return success;
}

