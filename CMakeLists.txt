cmake_minimum_required(VERSION 3.7)
project(CppDataStructure)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(CppDataStructure ${SOURCE_FILES})

add_executable(sort sort/merge_sort.cpp)