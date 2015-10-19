#ifndef META_CORE_DEBUG_H
#define META_CORE_DEBUG_H

#include <sstream>
#include <iostream>

namespace meta
{
  namespace core {
    enum LogLevel
    {
      eLogSpam,
      eLogDebug,
      eLogInfo,
      eLogWarn,
      eLogError,
      eLogLevels
    };

    template<typename TValue>
    void log (std::stringstream& s, TValue arg)
    {
      s << arg;
    }
    
    template<typename TValue, typename... TArgs>
    void log(std::stringstream& s, TValue arg, TArgs... args)
    {
      log (s, arg);
      log (s, args...);
    }
 
    template<typename... TArgs>
    void log(TArgs... args)
    {
      std::stringstream s;
      log(s, args...);
      s << std::endl;
      std::cerr << s.str();
    }
  }
}

#endif
