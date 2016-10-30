cmake_minimum_required (VERSION 2.8)
find_package(Protobuf REQUIRED)

add_executable (dispatcher main.cpp first.pb.cc )
target_link_libraries (dispatcher protobuf)
