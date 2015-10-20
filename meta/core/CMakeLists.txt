# core library for metanet

set(CORE_SRC
  "dht/kad.cc"
)

add_library(${CORE_NAME} ${CORE_SRC})
target_link_libraries(${CORE_NAME} ${DATATYPE_NAME} ${CRYPTO_NAME})