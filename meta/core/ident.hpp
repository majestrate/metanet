#ifndef META_CORE_IDENT_H
#define META_CORE_IDENT_H
#include "crypto/pubkey.hpp"


namespace meta
{
  namespace core
  {
    // our network identity
    // keys etc
    struct Identity
    {
      meta::crypto::PublicKey pubkey;
      meta::crypto::SecretKey seckey;
    };
  }
}

#endif
