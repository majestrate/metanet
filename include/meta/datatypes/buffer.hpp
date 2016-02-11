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
    SecureBuffer(const SecureBuffer&&) = delete;
    SecureBuffer(SecureBuffer &) = delete;
    ~SecureBuffer();
    buff & operator =(const buff &) = delete;
    buff & operator =(buff &) = delete;
    operator buff&();

    size_t size() const {
      return _data.size();
    }

    typedef typename buff::iterator iter;
    
    iter end() {
      return _data.end();
    }
    
    iter begin() {
      return _data.begin();
    }
  };

}
#endif
