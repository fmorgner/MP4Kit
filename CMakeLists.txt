cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11 -stdlib=libc++)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

set(SOURCE "")

project(MP4Kit)

add_subdirectory(src)
include_directories(include)

add_library(MP4Kit ${SOURCE})
target_link_libraries(MP4Kit c++ ncurses pthread)
