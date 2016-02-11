//
// meta/core/dht/kad.hpp
//
#ifndef META_CORE_DHT_KAD_H
#define META_CORE_DHT_KAD_H
#include <array>
#include <functional>
#include <cstring>
#include <vector>
#include <memory>
#include <map>

namespace meta
{
  namespace dht
  {

    
    static constexpr std::size_t keyspace_bytes = 32;
    static constexpr std::size_t keyspace_bits = keyspace_bytes * 8;
    
    typedef std::array<uint8_t, keyspace_bytes> Key;      
    typedef std::vector<uint8_t> Value;
    typedef std::array<uint8_t, keyspace_bytes> Distance;
    
    typedef std::pair<Key, Value> Entry;

    bool operator<(Key & k1, Key & k2);
    bool operator>(Key & k1, Key & k2);
    bool operator==(Key & k1, Key & k2);

    
    
    // function to calcuate distance between keys
    typedef std::function<Distance(Key,Key)> DistanceFunction;

    Distance XOR(Key k1, Key k2);


    typedef std::pair<std::map<Key, Value>, DistanceFunction> Router;

    typedef std::unique_ptr<Router> RouterPtr;
    
    bool RouterContainsKey(const RouterPtr & r, const Key & k);
    void RouterAdd(const RouterPtr & r, Key & k, Value & v);
    void RouterDel(const RouterPtr & r, Key & k);
    Entry RouterClosest(const RouterPtr & r, Key & k);

    RouterPtr CreateDHT();
  }
}
#endif
