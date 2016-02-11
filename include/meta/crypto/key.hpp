//
// meta/crypto/pubkey.hpp
//

#ifndef META_CRYPTO_KEY_H
#define META_CRYPTO_KEY_H

#include <meta/datatypes/buffer.hpp>
#include <string>

namespace meta
{
  namespace crypto
  {

    constexpr size_t key_bytes = 32;

    typedef SecureBuffer<key_bytes> KeyBuffer;
    typedef KeyBuffer SecretKey;
    typedef KeyBuffer PublicKey;
    
    bool DecodeKeyFromString(const std::string & keydata, KeyBuffer & dest);
    std::string EncodeKeyToString(KeyBuffer & dest);

    // get public key from secret key
    void SecretKeyGetPublicKey(SecretKey & sk, PublicKey & pk);

    // generate a secret key
    void GenerateSecretKey(SecretKey & sk);
    
  }
}
#endif
