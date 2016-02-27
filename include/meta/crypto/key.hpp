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
    typedef KeyBuffer SymmetricKey;

    
    bool DecodeKeyFromString(const std::string & keydata, KeyBuffer & dest);
    std::string EncodeKeyToString(KeyBuffer & dest);

    // get public key from secret key
    void SecretKeyGetPublicKey(SecretKey & sk, PublicKey & pk);

    // generate a secret key
    void GenerateSecretKey(SecretKey & sk);


    // do symmetric encryption
    // assumes aligned
    void EncryptSymmetric(SymmetricKey & k,
                          const uint8_t * inbuff, const size_t inlen,
                          uint8_t * outbuff, const size_t outlen);

    // do symmetric decryption
    // assumes aligned
    void DecryptSymmetric(SymmetricKey & k,
                          const uint8_t * inbuff, const size_t inlen,
                          uint8_t * outbuff, const size_t outlen);

    
    
  }
}
#endif
