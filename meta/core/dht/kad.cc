#include <meta/core/dht/kad.hpp>
#include <iostream>
#include <iomanip>
#include <algorithm>

namespace meta
{

  namespace dht
  {


    Distance XOR(Key k1 , Key k2)
    {
      Distance d;
      std::size_t idx = 0;
      while(idx < keyspace_bytes) {
        d[idx] = k1[idx] ^ k2[idx];
        idx++;
      }
      return d;
    }
    
    bool operator<(Key & k1, Key & k2) 
    {
      return std::memcmp(k1.data(), k2.data(), keyspace_bytes) < 0;
    }
    
    bool operator>(Key & k1, Key & k2) 
    {
      return std::memcmp(k1.data(), k2.data(), keyspace_bytes) > 0;
    }

    bool operator==(Key & k1, Key & k2) 
    {
      return std::memcmp(k1.data(), k2.data(), keyspace_bytes) == 0;
    }

    bool RouterContainsKey(const RouterPtr & r,const Key & k) {
      return r->first.find(k) != r->first.end();
    }

    void RouterAdd(const RouterPtr & r, Key & k, Value & v) {
      r->first[k] = v;
    }

    void RouterDel(const RouterPtr & r, Key & k) {
      auto itr = r->first.find(k);
      if ( itr != r->first.end()) {
        r->first.erase(itr);
      }
    }

    // get entry closest to k 
    Entry RouterClosest(const RouterPtr & r, Key & k) {
      Distance dist;
      dist.fill(0xff);
      Entry ret;
      for ( auto & i : r->first ) {
        Distance d = r->second(i.first, k);
        if ( d < dist ) {
          dist = d;
          ret.first = i.first;
          ret.second = i.second;
        }
      }
      return ret;
    }
    
    RouterPtr CreateDHT() {
      return std::make_unique<Router>(std::map<Key, Value>(), XOR);
    }
  }
}
