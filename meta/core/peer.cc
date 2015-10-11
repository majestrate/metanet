//
// meta/core/peer.cc
//                                                                      
                                                                        
#include "core/peer.hpp"                                                
                                                                        
namespace meta                                                          
{                                                                       
  namespace core                                                        
  {
    static const char * peer_string_delimiter = " ";
    
    bool PeerInfo::LoadFromString(const std::string & peer_string)      
    {
      // needs 1 space only
      auto space_idx = peer_string.find(peer_string_delimiter);
      if (space_idx == std::string::npos || space_idx == 0 || space_idx + 1 == peer_string.size())
      {
        return false;
      } 
      // first  part is the address string 
      peerAddr = peer_string.substr(space_idx);
      return crypto::PublicKeyDecode(peer_string.substr(peer_string.size() - space_idx, space_idx + 1), identKey); 
    }

    PeerSession::PeerSession(const PeerInfo & info) : m_peerinfo(info) {}
    
  }
}
