#ifndef META_CORE_EV_H
#define META_CORE_EV_H
#include <netinet/in.h>
#include <sys/types.h>

#include <memory>
#include <string>

namespace meta
{
  namespace core
  {

    // autoclosing file descriptor
    struct FD {
      int fd;
      
      FD();
      FD(int d);
      ~FD();
      
      operator int();
    };

    struct EventCorePimpl;
    
    struct EventCore
    {
      EventCore();
      ~EventCore();
      void RegisterLinkFD(int af, int fd);
      EventCorePimpl *impl;
    };
    
    typedef std::unique_ptr<EventCore> EventCoreptr;

    // run mainloop
    void Run(const EventCoreptr & core);
  }
}
#endif
