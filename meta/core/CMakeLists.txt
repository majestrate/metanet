# core library for metanet

set(CORE_SRC
  "dht/kad.cc"
  "ev.cc"
  "ev_impl.cc"
  "udp.cc"
)

include_directories(${LIBUV_INCLUDE_DIRS})
link_directories(${LIBUV_LIBRARY_DIRS})

add_library(${CORE_NAME} ${CORE_SRC})

target_link_libraries(${CORE_NAME} ${LIBUV_LIBRARIES} ${DATATYPE_NAME} ${CRYPTO_NAME})
