cmake_minimum_required (VERSION 2.8)
find_package (Threads REQUIRED)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Werror -Wall" )
set (LIBS muduo_net_cpp11 muduo_base_cpp11 pthread )
add_executable (client client.cpp)
add_executable (server server.cpp)
target_link_libraries (client ${LIBS})
target_link_libraries (server ${LIBS})
