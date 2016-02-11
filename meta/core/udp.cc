#include <meta/core/link.hpp>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#include "ev_impl.hpp"

namespace meta
{
  namespace core
  {
    template<>
    NetLink<sockaddr_in6>::NetLink() : af(AF_INET6), fd(socket(AF_INET6, SOCK_DGRAM, 0)) {}

    template<>
    bool NetLink<sockaddr_in6>::ParseAddr(const std::string & ifname, const uint16_t p, sockaddr_in6 & addr) {
      addr.sin6_port = htons(p);
      addr.sin6_family = AF_INET6;
      addr.sin6_flowinfo = 0;
      addr.sin6_scope_id = 0;
      return inet_pton(AF_INET6, ifname.c_str(), addr.sin6_addr.s6_addr) == 1;
    }
  }
}
