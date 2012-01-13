cmake_minimum_required(VERSION 2.8)

project(STEAMKNIGHT CXX)
set(CMAKE_CXX_FLAGS_RELEASE "-ansi -pedantic -Wall -s -O2")
set(CMAKE_CXX_FLAGS_DEBUG "-ansi -pedantic -Wall -g")

add_subdirectory(src)
