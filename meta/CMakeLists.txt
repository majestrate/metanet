# set some variables for names
set(META_NAME "meta")
set(CORE_NAME "metacore")
set(CRYPTO_NAME "metacrypto")
message("core is" ${CORE_NAME})
message("crypto is" ${CRYPTO_NAME})

# include path is .
include_directories(".")

# add crypto sub directory
add_subdirectory(crypto)
# add core sub directory
add_subdirectory(core)

set(METAD_SRC
  "daemon.cc"
  "version.cc"
)

# metad exe name
set(METAD_NAME metad)

# metad main executable
add_executable(${METAD_NAME} ${METAD_SRC})

# add target libs
target_link_libraries(metad ${CRYPTO_NAME})
target_link_libraries(metad ${CORE_NAME})

install(
  TARGETS ${METAD_NAME}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
