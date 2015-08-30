#include "version.hpp"
#include "core/debug.hpp"

using namespace meta;

// metad main
int main(int argc, char * argv[])
{
  auto version_string = version();
  core::log("starting up", version_string);
}
