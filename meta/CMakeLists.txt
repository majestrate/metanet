
pkg_check_modules(LIBUV REQUIRED libuv)

include_directories(${LIBUV_INCLUDE_DIRS})
# include path is .
include_directories(".")

# add crypto sub directory
add_subdirectory(crypto)
# add core sub directory
add_subdirectory(core)
# add datatypes directory
add_subdirectory(datatypes)

set(METAD_SRC
  "daemon.cc"
  "version.cc"
)

# metad exe name
set(METAD_NAME metad)

# metad main executable
add_executable(${METAD_NAME} ${METAD_SRC})

# add target libs
target_link_libraries(${METAD_NAME} ${CRYPTO_NAME})
target_link_libraries(${METAD_NAME} ${DATATYPE_NAME})
target_link_libraries(${METAD_NAME} ${CORE_NAME})
target_link_libraries(${METAD_NAME} ${LIBUV_LIBRARIES})

install(
  TARGETS ${METAD_NAME}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
