#include <string>
#include <iostream>

bool stringToDouble(const std::string &_str, double &io_result)
{

  io_result = std::stod(_str);

  return true;
}

