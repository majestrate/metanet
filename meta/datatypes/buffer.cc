#include <meta/datatypes/buffer.hpp>
#include <sodium/utils.h>

namespace meta
{
  template<size_t len>
  SecureBuffer<len>::SecureBuffer() {
    sodium_memzero(_data.data(), _data.size());
  }
  template<size_t len>  
  SecureBuffer<len>::~SecureBuffer() {
    sodium_memzero(_data.data(), _data.size());
  }
  
  template<size_t len>
  SecureBuffer<len>::operator buff() {
    return _data;
  }
}
