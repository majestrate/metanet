//
// meta/core/peer.hpp
//
#ifndef META_CORE_PEER_H
#define META_CORE_PEER_H

#include "core/message.hpp"
#include "crypto/pubkey.hpp"

#include <memory>


namespace meta
{
  namespace core
  {
    // information needed to connect to a peer
    struct PeerInfo
    {
      // their public key
      crypto::PublicKey identKey;
      // their reachable address
      std::string peerAddr;

      bool LoadFromString(const std::string & peer_string);
    };

    
    // a session with a peer
    class PeerSession
    {
    public:
      PeerSession(const PeerInfo & info);
      bool SendLinkMessage(const LinkMessage & msg);
    private:
      PeerInfo m_peerinfo;
    };
    typedef std::shared_ptr<PeerSession> PeerSessionPtr;
  }
}

#endif
