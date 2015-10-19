#ifndef META_CORE_NET_H
#define META_CORE_NET_H

#include <string>
#include <vector>

namespace meta
{
  namespace core
  {
    
    // network core
    class Network
    {

    public:
      virtual ~Network() {}
      virtual void AddPeer(const std::string & peer_string) {}
      virtual void Run() {}
    };
  }
}

#endif
