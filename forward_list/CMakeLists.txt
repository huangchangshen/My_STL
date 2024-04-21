cmake_minimum_required(VERSION 3.20)
project(forward_list)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(main main.cpp forward_list_iterator/const_iterator.h)
