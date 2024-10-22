cmake_minimum_required(VERSION 3.28)
project(performance-and-optimization)

set(CMAKE_CXX_STANDARD 23)

add_executable(copy-constructor copy-constructor.cpp)

add_executable(move-semantics move-semantics.cpp)

add_executable(smart-pointers smart-pointers.cpp)

add_executable(strings strings.cpp)

add_executable(value-types value-types.cpp)
