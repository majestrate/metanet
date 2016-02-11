#include <meta/datatypes/buffer.hpp>
#include <sodium/utils.h>

namespace meta
{
  template <>
  SecureBuffer<32ul>::SecureBuffer() {
    sodium_memzero(_data.data(), _data.size());
  }

  template <>
  SecureBuffer<32ul>::~SecureBuffer() {
    sodium_memzero(_data.data(), _data.size());
  }
  
  template<>
  SecureBuffer<32ul>::operator buff&() {
    return _data;
  }
}
