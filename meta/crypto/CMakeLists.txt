
# find packages

# sodium
find_library(SODIUM_LIBRARY_PATH sodium REQUIRED)
find_path(SODIUM_INCLUDE_DIR sodium REQUIRED)
if(NOT DEFINED SODIUM_INCLUDE_DIR OR NOT DEFINED SODIUM_LIBRARY_PATH)
  message(SEND_ERROR "Could not find Sodium")
else()
  message(STATUS "Sodium Libraries: " ${SODIUM_LIBRARY_PATH})
  message(STATUS "Sodium Includes: " ${SODIUM_INCLUDE_DIR})
endif()

set(CRYPTO_SRC
  "encrypt.cc"
  "decrypt.cc"
  "pubkey.cc"
  "base58.cc"
)

add_library(${CRYPTO_NAME} ${CRYPTO_SRC})
target_link_libraries(${CRYPTO_NAME} ${SODIUM_LIBRARY_PATH})
