//
// meta/crypto/base58.hpp
//
#ifndef META_CRYPTO_BASE58_H
#define META_CRYPTO_BASE58_H

#include <string>
#include <vector>

namespace meta
{
  namespace crypto
  {
    bool DecodeBase58(const char * data, std::vector<char> const & dest);
    std::string EncodeBase58(const unsigned char * pbegin, const unsigned char * pend);
  }
}

#endif
