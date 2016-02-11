#include <meta/core/ev.hpp>
#include "ev_impl.hpp"
#include <cstring>
#include <memory>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

namespace meta
{
  namespace core
  {
    EventCore::EventCore() : impl(new EventCorePimpl) {}

    EventCore::~EventCore() { delete impl; }


    void Run(const EventCoreptr & core) {
      core->impl->Mainloop();
    }

    void EventCore::RegisterLinkFD(int af, int fd) {
      impl->AddLinkFd(af, fd);
    }
    
  }
}
