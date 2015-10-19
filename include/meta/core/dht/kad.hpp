//
// meta/core/dht/kad.hpp
//
#ifndef META_CORE_DHT_KAD_H
#define META_CORE_DHT_KAD_H
#include <array>
#include <functional>
#include <unordered_map>
#include <cstring>
#include <memory>
#include <list>

namespace meta
{
  namespace dht
  {

    
    static constexpr std::size_t keyspace_bytes = 32;
    static constexpr std::size_t keyspace_bits = keyspace_bytes * 8;
    
    typedef std::array<uint8_t, keyspace_bytes> Key;      
    typedef std::array<uint8_t, keyspace_bytes> Value;
    typedef std::array<uint8_t, keyspace_bytes> Distance;
    
    typedef std::pair<Key, Value> Entry;

    typedef std::shared_ptr<Key> Keyptr;
    typedef std::shared_ptr<Value> Valueptr;
    
    bool operator<(Key & k1, Key & k2);
    bool operator>(Key & k1, Key & k2);
    bool operator==(Key & k1, Key & k2);

    
    
    // function to calcuate distance between keys
    typedef std::function<Distance(Key,Key)> DistanceFunction;

    Distance XOR(Key k1, Key k2);


    typedef std::pair<std::list<Entry>, DistanceFunction> Router;

    typedef std::shared_ptr<Router> RouterPtr;
    
    bool RouterContainsKey(RouterPtr r, const Key & k);
    void RouterAdd(RouterPtr r, Key & k, Value & v);
    void RouterDel(RouterPtr r, Key & k);
    Entry RouterClosest(RouterPtr r, Key & k);

    void RouterDumpTable(RouterPtr r, std::ostream & os);

    void Dump(const std::array<uint8_t, keyspace_bytes> & k, std::ostream & os);
    
    // create our dht instance
    RouterPtr CreateDHT();
    
  }
}
#endif
