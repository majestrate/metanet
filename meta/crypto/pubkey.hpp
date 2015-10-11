//
// meta/crypto/pubkey.hpp
//

#ifndef META_CRYPTO_PUBKEY_H
#define META_CRYPTO_PUBKEY_H

#include <array>
#include <string>

namespace meta
{
  namespace crypto
  {
    typedef std::array<uint8_t, 32> PublicKey;
    typedef std::array<uint8_t, 32> SecretKey;

    bool PublicKeyDecode(std::string const & keydata, PublicKey const & key);
  }
}
#endif
