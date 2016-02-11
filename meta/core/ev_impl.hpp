#ifndef META_CORE_EV_IMPL_HPP
#define META_CORE_EV_IMPL_HPP
#include <string>
#include <cstdint>
#include <future>

namespace meta
{
  namespace core
  {

    constexpr size_t max_recv_mtu = 1500;
    constexpr size_t max_links = 8;
    
    class EventCorePimpl {
    public:
      EventCorePimpl();
      void Mainloop();
      void Wait();
      void AddLinkFd(int af, int fd);
    private:
      void Recv(int linkidx);
      void Error(int linkidx);
      size_t recvsize;
      uint8_t recvbuff[max_recv_mtu];
      int linkfds[max_links];
      int linkafs[max_links];
      size_t numlinks;
      std::promise<void> done;
    };
  }
}


#endif
