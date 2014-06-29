cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(library library.cxx)
add_library(system system.cxx)
add_library(world world.cxx)
