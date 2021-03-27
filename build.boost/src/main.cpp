#include <iostream>
#include <string>
#include <boost/regex.hpp> //! regex need library, is not header file only.

int main()
{
  std::string line;
  boost::regex pat("^hello (.*)");

  while (std::getline(std::cin, line))
  {
    if (line == "exit") break;

    boost::smatch matches;
    if (boost::regex_match(line, matches, pat))
    {
      std::cout << matches[1] << std::endl;
    }
  }

  return 0;
}