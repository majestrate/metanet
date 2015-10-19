#include <meta/core/dht/kad.hpp>
#include <assert.h>


void basic_test() {

  meta::dht::Key k1;
  k1.fill(0);
  meta::dht::Value v1;
  v1.fill(0xff);
  meta::dht::Key k2;
  k2.fill(0);
  meta::dht::Value v2;
  v2.fill(0);

  assert(k1 == k2);

  
  k1[1] = 1;
  
  assert(k1 != k2);
  assert(k1 > k2);

  k2[0] = 1;

  assert(k1 != k2);
  assert(k1 < k2);

  auto r = meta::dht::CreateDHT();

  assert( ! meta::dht::RouterContainsKey(r, k1) );

  meta::dht::RouterAdd(r, k1, v1);

  assert( meta::dht::RouterContainsKey(r, k1) );

  meta::dht::RouterDel(r, k1);

  assert( ! meta::dht::RouterContainsKey(r, k1) );

  meta::dht::RouterDel(r, k2);

  meta::dht::Key k3;
  k3.fill(3);
  meta::dht::Value v3;
  v3.fill(4);

  meta::dht::Key k4;
  k4.fill(5);
  meta::dht::Value v4;
  v4.fill(6);

  meta::dht::RouterAdd(r, k3, v3);
  meta::dht::RouterAdd(r, k4, v4);

  meta::dht::Entry c;
  
  c = meta::dht::RouterClosest(r, k3);

  assert (c.second == v3);
  assert (c.first == k3);

  c = meta::dht::RouterClosest(r, k4);

  assert (c.second == v4);
  assert (c.first == k4);

  meta::dht::RouterDel(r, k4);

  c = meta::dht::RouterClosest(r, k4);

  assert (c.second == v3);
  assert (c.first == k3);
}

int main(int argc, char * argv[]) {
  basic_test();
}
