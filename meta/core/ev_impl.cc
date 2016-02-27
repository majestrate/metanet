#include "ev_impl.hpp"
#include <arpa/inet.h>
#include <cstdlib>
#include <netinet/in.h>
#include <net/ethernet.h>
#ifdef __linux__
#include <linux/if_packet.h>
#else
#error "your platform does not support sockaddr_ll"
#endif
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

namespace meta
{
  namespace core
  {
    constexpr size_t eth_mtu_limit = 1500;
    constexpr size_t udp_mtu_limit = 1500;
    constexpr uint16_t eth_proto = 0xD1C3;
    
    void EventCorePimpl::Wait() {
      auto ftr = done.get_future();
      ftr.wait();
    }
    
    void EventCorePimpl::Mainloop() {
      int res = 0;
      bool has_fd = false;
      do {
        timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 0;
        fd_set fds;
        FD_ZERO(&fds);
        for ( size_t idx = 0 ; idx < max_links; idx ++ ) {
          if (linkfds[idx] != -1) {
            has_fd = true;
            FD_SET(linkfds[idx], &fds);
          }
        }

        if (has_fd) {
          res = select(2, &fds, nullptr, nullptr, &tv);
          if (res > 0) {
            for (size_t idx = 0 ; idx < max_links ; idx ++ ) {
              if ( FD_ISSET(linkfds[idx], &fds) ) {
                Recv(idx);
              }
            }
          } else if (res == 0 ) {
            // no data
          } else {
            // error
            perror("select()");
          }
        }
      } while(res != -1 && has_fd);
      done.set_value();
    }

    void EventCorePimpl::AddLinkFd(int af, int fd) {
      for ( size_t idx = 0 ; idx < max_links ; ++idx ) {
        if (linkafs[idx] == -1 && linkfds[idx] == -1) {
          linkafs[idx] = af;
          linkfds[idx] = fd;
          return;
        }
      }
    }

    void EventCorePimpl::Recv(int linkidx) {
      sockaddr * saddr = nullptr;
      sockaddr_in6 saddr_in6;
      sockaddr_in saddr_in;
      sockaddr_ll saddr_ll;
      
      switch(linkafs[linkidx]) {
      case AF_INET6:
        saddr = (sockaddr*) &saddr_in6;
        break;
      case AF_INET:
        saddr = (sockaddr*) &saddr_in;
        break;
      case AF_PACKET:
        saddr = (sockaddr*) &saddr_ll;
        break;
      }
      if (saddr) {
        socklen_t saddrlen;
        ssize_t rbytes = recvfrom(linkfds[linkidx], recvbuff, max_recv_mtu, 0, saddr, &saddrlen);
        if (rbytes > 0) {
          // we got a packet
          const size_t l = rbytes;
          packet.GotPacketFrom(saddr, recvbuff, l);
        } else {
          // error
          perror("recvfrom()");
          Error(linkidx);
        }
      }
    }

    void EventCorePimpl::Error(int linkidx) {
      if(linkfds[linkidx] != -1) {
        close(linkfds[linkidx]);
        linkfds[linkidx] = -1;
        linkafs[linkidx] = -1;
        --numlinks;
      }
    }
    
    EventCorePimpl::EventCorePimpl() : numlinks(0) {
      memset(linkfds, -1, max_links);
      memset(linkafs, -1, max_links);
    }
  }
}
