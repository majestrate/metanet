#ifndef META_CORE_NET_H
#define META_CORE_NET_H
#include <functional>
#include <string>
#include <vector>
#include <meta/crypto/key.hpp>
#include <meta/datatypes/link.hpp>


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
    
    class PeerSession
    {
    public:
      // decrypt a message with our private key
      typedef std::function<bool(meta::crypto::KeyBuffer,meta::Messageptr)> DecryptFunction;
      
      void HandlePacket(const uint8_t * begin, const uint8_t * end, DecryptFunction decf);
      void SendMessage(meta::Messageptr msg);
      
    private:
      
    };
  }
}

#endif
