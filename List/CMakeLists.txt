cmake_minimum_required(VERSION 3.20)
project(List)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(./list_iterator/)

add_executable(List main.cpp)
