cmake_minimum_required(VERSION 3.14)

project(VECTOR)

set(CMAKE_CXX_STANDARD 17)

//添加头文件的搜索路径,用空格隔开
include_directories(./ ./include)

//给所有的目标文件加上编译选项
add_compile_options(-g -Wunused)

//给指定文件加上编译选项
target_compile_options(main PUBLIC -Wall -Werror)


//添加编译文件生成目标文件

//指定文件夹所有.cpp文件
file(GLOB_RECURSE SOURCE ./*.cpp)

//从某些源文件创建库文件
set(MUL_SOURCES ./ ./mul)
add_library(mul STATIC ${MUL_SOURCES})  //STATIC 静态库         SHARED 动态库

link_directories(./)
link_libraries(mul)


//链接到指定目标文件
target_link_directories()
target_link_libraries(main mul)

add_executable(main main.cpp)
add_executable(main ${SOURCE} main.cpp)
