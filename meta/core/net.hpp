#ifndef META_CORE_NET_H
#define META_CORE_NET_H

#include <string>
#include <vector>

#include "crypto/pubkey.hpp"

namespace meta
{
  namespace core
  {
    
    // network concensous
    class Network
    {

    public:
      Network();
      ~Network();
      void AddPeer(const std::string & peer_string);
      void Run();
    private:
      std::vector<std::string> m_peers;
    };
  }
}

#endif
