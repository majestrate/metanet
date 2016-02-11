#include <meta/version.hpp>
#include <sstream>



namespace meta
{

  constexpr int major_version = 0;
  constexpr int minor_version = 0;

  std::string version()
  {
    std::stringstream ss;
    ss << "metad-";
    ss << (int)major_version;
    ss << ".";
    ss << (int)minor_version;
    return ss.str();
  }
  
}
