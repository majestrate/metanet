//
// meta/crypto/pubkey.cc
//
#include <meta/crypto/key.hpp>
#include <meta/datatypes/base58.hpp>


namespace meta
{
  namespace crypto
  {
    bool DecodeKeyFromString(std::string const & keydata, std::array<uint8_t, 32> & dest)
    {
      std::vector<uint8_t> vec;
      if ( DecodeBase58(keydata.c_str(), vec) && vec.size() == dest.size()) {
        std::copy(vec.begin(), vec.end(), dest.begin());
        return true;
      } else {
        return false;
      }
    }
  }
}
