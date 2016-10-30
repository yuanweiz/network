cmake_minimum_required ( VERSION 2.8)
include_directories ("../muduo/")
#link_directories ("") #use muduo debug build
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L/data/code/network/lib")
add_subdirectory ("./chat")
add_subdirectory ("./filetransfer")
