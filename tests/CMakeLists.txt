# add tests here

include_directories(".")

set(DHT_TEST "testdht")
add_executable(${DHT_TEST} ${DHT_TEST}.cc)
target_link_libraries(${DHT_TEST} ${CORE_NAME})
target_link_libraries(${DHT_TEST} ${DATATYPE_NAME})