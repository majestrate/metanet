#ifndef META_CORE_LINK_H
#define META_CORE_LINK_H

#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <meta/core/ev.hpp>

namespace meta
{
  namespace core
  {

    // link layer packet io
    template<typename SAddr>
    struct NetLink {
      NetLink();
      ~NetLink() {
        if (fd != -1) {
          close(fd);
          fd = -1;
        }
      }
      static bool ParseAddr(const std::string & ifname, const uint16_t p, SAddr & addr);
      bool Bind(const SAddr & bindaddr) const {
        return bind(fd, (const sockaddr*) &bindaddr, sizeof(SAddr)) != -1;
      }
      ssize_t SendTo(const SAddr * daddr, const uint8_t * dataptr, const size_t datalen);
      ssize_t RecvFrom(SAddr * saddr, uint8_t * dataptr, const size_t datalen);

      void Register(const EventCoreptr & ev) const {
        ev->RegisterLinkFD(af, fd);
      }
      
      int fd, af;
    };
    
  }
}

#endif
