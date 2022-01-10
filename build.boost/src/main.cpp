#include <iostream>
#include <string>
#include <boost/regex.hpp> //! regex need library, is not header file only.

bool showprompt();
std::string trim(std::string const&);

int main()
{
  std::string line;
  boost::regex pat("^hello (.*)");

  while (showprompt() && std::getline(std::cin, line))
  {
    line = trim(line);
    if (line == "exit") break;

    boost::smatch matches;
    if (boost::regex_match(line, matches, pat))
    {
      std::cout << matches[1] << std::endl;
    }
  }

  return 0;
}

bool showprompt()
{
  std::cout << "> ";
  return true;
}
std::string trim(std::string const& s)
{
  std::string tmp = s.substr(0, s.find_last_not_of(" \t") + 1);
  return tmp;
}