#include <meta/core/dht/kad.hpp>
#include <assert.h>

#include <iostream>

void basic_test() {
  std::cout << "basic test " << std::flush;
  
  meta::dht::Key k1;
  k1.fill(0);
  meta::dht::Value v1;
  v1.push_back(1);
  meta::dht::Key k2;
  k2.fill(0);
  meta::dht::Value v2;
  v2.push_back(2);
  assert(k1 == k2);

  
  k1[1] = 1;
  
  assert(k1 != k2);
  assert(k1 > k2);
  
  k2[0] = 1;

  assert(k1 != k2);
  assert(k1 < k2);

  const meta::dht::RouterPtr r = meta::dht::CreateDHT();

  assert( ! meta::dht::RouterContainsKey(r, k1) );

  meta::dht::RouterAdd(r, k1, v1);

  assert( meta::dht::RouterContainsKey(r, k1) );

  meta::dht::RouterDel(r, k1);

  assert( ! meta::dht::RouterContainsKey(r, k1) );

  meta::dht::RouterDel(r, k2);

  meta::dht::Key k3;
  k3.fill(3);
  meta::dht::Value v3;
  v3.push_back(3);

  meta::dht::Key k4;
  k4.fill(4);
  meta::dht::Value v4;
  v4.push_back(4);

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

void message_test() {
  std::cout << "message test " << std::flush;
}

int main(int argc, char * argv[]) {
  basic_test();
  std::cout << "okay" << std::endl;
  message_test();
  std::cout << "okay" << std::endl;
}
