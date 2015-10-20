//
// meta/datatypes/base58.hpp
//
#ifndef META_TYPES_BASE58_H
#define META_TYPES_BASE58_H

#include <string>
#include <vector>

namespace meta
{
  bool DecodeBase58(const char * data, std::vector<uint8_t> const & dest);
  std::string EncodeBase58(const uint8_t * pbegin, const uint8_t * pend);
}

#endif
