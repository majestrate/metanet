#include <meta/version.hpp>
#include <meta/core/ev.hpp>
#include <meta/core/link.hpp>
#include <meta/core/dht/kad.hpp>
#include <string>
#include <iostream>

// metad main
int main(int argc, char * argv[])
{
  if (argc != 2) {
    std::cout << "usage: " << argv[0] << " ip6addr" << std::endl;
    return -1;
  }
  
  std::string version_string = meta::version();
  std::cout << "starting up " << version_string;
  std::cout << std::endl;
  const meta::core::EventCoreptr ev = std::make_unique<meta::core::EventCore>();
  const meta::dht::RouterPtr dht = meta::dht::CreateDHT();
  typedef meta::core::NetLink<sockaddr_in6> IPLink;
  IPLink udp;
  std::cout << "bind... ";
  const uint16_t port = 9000;
  const std::string addr(argv[1]);
  sockaddr_in6 bindaddr;
  if ( IPLink::ParseAddr(addr, port, bindaddr) ) {
    if ( udp.Bind(bindaddr) ) {
      std::cout << "okay";
      udp.Register(ev);
    } else {
      // failed to bind
      std::cout << "failed to bind udp" << std::endl;
      return -1;
    }
  } else {
    std::cout << "failed to parse address" << std::endl;
  }
  std::cout << std::endl;
  std::cout << "running mainloop" << std::flush;
  meta::core::Run(ev);
  std::cout << std::endl;
}
