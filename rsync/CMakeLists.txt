cmake_minimum_required (VERSION 2.8)
find_package (Threads REQUIRED)
find_package (Protobuf REQUIRED)
project (filetransfer)

add_custom_target(proto protoc FileTransfer.proto --cpp_out=. 
    WORKING_DIRECTORY  ${PROJECT_SOURCE_DIR} )

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Werror -Wall" )
add_library (rpc FileTransfer.pb.cc  Codec.cpp Dispatcher.cpp)
set (LIBS rpc protobuf muduo_net_cpp11 muduo_base_cpp11 pthread )
add_executable (ftclient client.cpp )
add_executable (ftserver server.cpp )
target_link_libraries (ftclient ${LIBS})
target_link_libraries (ftserver ${LIBS})
