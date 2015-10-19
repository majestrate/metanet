#include <meta/version.hpp>
#include <meta/core/debug.hpp>
#include <meta/core/net.hpp>
#include <string>

using namespace meta;

// metad main
int main(int argc, char * argv[])
{
  auto version_string = version();
  core::log("starting up ", version_string);
  core::Network net;
  int idx = 1;
  while(idx < argc) {
    std::string peer = argv[idx++];
    net.AddPeer(peer);
  }
  
  core::log("run network");
  net.Run();
  core::log("ended");
}
