//
// meta/datatypes/buffer.hpp
//
#ifndef META_TYPES_BUFFER_H
#define META_TYPES_BUFFER_H
#include <array>
#include <vector>

namespace meta
{
  template <size_t len>
  struct SecureBuffer {
    typedef std::array<uint8_t, len> buff;
    buff _data;
    SecureBuffer();
    ~SecureBuffer();
    buff & operator =(buff & other) = delete;
    operator buff();
  };

}
#endif
