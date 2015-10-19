#include <meta/version.hpp>
#include <sstream>



namespace meta
{

  constexpr int major_version = 0;
  constexpr int minor_version = 0;

  const char * version()
  {
    std::stringstream ss;
    ss << "metad-";
    ss << major_version;
    ss << ".";
    ss << minor_version;
    return ss.str().c_str();
  }
  
}
