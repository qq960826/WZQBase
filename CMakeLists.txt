cmake_minimum_required(VERSION 2.8)
project(WZQBase)
set (CMAKE_CXX_STANDARD 11)

add_subdirectory(library)
include_directories(library/json/include)
include_directories(include)
add_subdirectory(source)
add_subdirectory(unittest)

