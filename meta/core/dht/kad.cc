#include <meta/core/dht/kad.hpp>
#include <meta/datatypes/link.hpp>
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

    bool RouterContainsKey(RouterPtr r,const Key & k) {
      auto itr = std::find_if(r->first.begin(), r->first.end(), [k](Entry & i){ return i.first == k; });
      return itr != r->first.end();
    }

    void RouterAdd(RouterPtr r, Key & k, Value & v) {
      Entry e;
      std::copy(k.begin(), k.end(), e.first.begin());
      std::copy(v.begin(), v.end(), e.second.begin());
      r->first.push_back(e);
      r->first.sort();
      r->first.unique();
      
    }

    void RouterDel(RouterPtr r, Key & k) {
      auto itr = r->first.begin();
      while(itr != r->first.end()) {
        if (itr->first == k) {
          // found one
          r->first.erase(itr);
          // return don't remove any others
          return;
        }
        itr ++;
      }
    }

    // get entry closest to k 
    Entry RouterClosest(RouterPtr r, Key & k) {
      Distance dist;
      dist.fill(0xff);
      Entry ret;
      for ( auto & i : r->first ) {
        Distance d = r->second(i.first, k);
        if ( d < dist ) {
          std::copy(d.begin(), d.end(), dist.begin());
          std::copy(i.first.begin(), i.first.end(), ret.first.begin());
          std::copy(i.second.begin(), i.second.end(), ret.second.begin());
        }
      }
      return ret;
    }

    void Dump(const std::array<uint8_t, keyspace_bytes> & k, std::ostream & os) {
        os << "0x";
        std::size_t idx = 0;
        while(idx < keyspace_bytes) {
          os << std::hex << std::setw(2) << std::setfill('0') << (int) k[idx];
          idx ++;
        }
    }
    
    void RouterDumpTable(RouterPtr r, std::ostream & os) {
      os << "routing table:" << std::endl;
      for ( auto & i : r->first ) {
        Dump(i.first, os);
        os << " -> ";
        Dump(i.second, os);
        os << std::endl;
      }
    }
    
    RouterPtr CreateDHT() {
      RouterPtr r = std::make_shared<Router>();
      r->second = XOR;
      return r;
    }
  }
}
