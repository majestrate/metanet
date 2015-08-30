#include "version.hpp"
#include <cstdio>



namespace meta
{

  constexpr int major_version = 0;
  constexpr int minor_version = 0;

  const char * version()
  {
    char version_string[128];
    sprintf(version_string ,"metad-%d-%d", major_version, minor_version);
    return version_string;
  }
  
}
