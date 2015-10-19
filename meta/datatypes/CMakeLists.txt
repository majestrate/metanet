# datatypes for metanet


set(DATATYPE_SRC
  "generic.cc"
  "certificate.cc"
)

add_library(${DATATYPE_NAME} ${DATATYPE_SRC})
target_link_libraries(${DATATYPE_NAME} ${CRYPTO_NAME})