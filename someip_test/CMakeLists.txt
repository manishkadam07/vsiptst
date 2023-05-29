cmake_minimum_required (VERSION 2.8)

set (CMAKE_CXX_FLAGS "-g -std=c++0x")
set (CMAKE_PREFIX_PATH /home/mkadam/vsomeip)
find_package (vsomeip3 REQUIRED)
find_package( Boost 1.74.0 COMPONENTS system thread log REQUIRED )

include_directories (
    ${Boost_INCLUDE_DIR}
    ${VSOMEIP_INCLUDE_DIRS}
)

add_executable(service-example service-example.cpp)
target_link_libraries(service-example vsomeip3 ${Boost_LIBRARIES})

add_executable(client-example client-example.cpp)
target_link_libraries(client-example vsomeip3 ${Boost_LIBRARIES})

add_executable(subnot subnot.cpp)
target_link_libraries(subnot vsomeip3 ${Boost_LIBRARIES})
