//
// meta/core/net.cc
//
// networking core for metanet
#include "core/debug.hpp"
#include "core/net.hpp"
#include "core/peer.hpp"

#include <thread>
#include <memory>

namespace meta
{
  namespace core
  {

    Network::Network()
    {
    }

    Network::~Network()
    {
    }

    void Network::AddPeer(const std::string & peer_string)
    {
      m_peers.push_back(peer_string);
    }

    void Network::Run()
    {
      log("we started up, running mainloop");

      std::vector <PeerSessionPtr> sessions;

      // start sessions
      for ( auto & peer : m_peers )
      {
        PeerInfo info;
        if (info.LoadFromString(peer)) {
          auto sess = std::make_shared<PeerSession>(info);
          sessions.push_back(sess);
        } else {
          log("invalid peer string detected: ", peer);
        }
      }
      
      // session ticks
      for ( auto & sess_ptr : sessions )
      {
        std::this_thread::sleep_for(std::chrono::seconds(1));
      }

      log("exiting mainloop");
    }
  }
}
