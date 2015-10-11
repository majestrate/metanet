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
    bool Base58Decode(std::string const & data, std::vector<char> const & dest);
  }
}

#endif
