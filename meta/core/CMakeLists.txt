# core library for metanet


set(CORE_SRC
  "net.cc"
  "peer.cc"
)

add_library(${CORE_NAME} ${CORE_SRC})
target_link_libraries(${CORE_NAME} ${CRYPTO_NAME})