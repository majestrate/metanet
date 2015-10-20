#ifndef META_TYPES_LINK_HPP

#include <meta/datatypes/buffer.hpp>
#include <memory>
#include <vector>


namespace meta
{
  static constexpr size_t link_header_size = 128;
  typedef SecureBuffer<link_header_size> MessageHeader;
  
  struct Message
  {
    MessageHeader hdr;
    std::vector<uint8_t> body;
  };
  
  typedef std::shared_ptr<Message> Messageptr;
  
}



#endif
