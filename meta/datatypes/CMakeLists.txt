# datatypes for metanet


set(DATATYPE_SRC
  "generic.cc"
  "base58.cc"
  "certificate.cc"
  "buffer.cc"
)

add_library(${DATATYPE_NAME} ${DATATYPE_SRC})
target_link_libraries(${DATATYPE_NAME} ${CRYPTO_NAME})