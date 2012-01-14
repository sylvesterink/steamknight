cmake_minimum_required(VERSION 2.8)

project(STEAMKNIGHT CXX)

# The version number.
set (STEAMKNIGHT_VERSION_MAJOR 0)
set (STEAMKNIGHT_VERSION_MINOR 0)
set (STEAMKNIGHT_VERSION_BUILD 1)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
    "${STEAMKNIGHT_SOURCE_DIR}/src/SteamknightConfig.h.in"
    "${STEAMKNIGHT_BINARY_DIR}/src/SteamknightConfig.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${STEAMKNIGHT_BINARY_DIR}/src")

# Build flags for Debug and Release builds
set(CMAKE_CXX_FLAGS_RELEASE "-ansi -pedantic -Wall -s -O2")
set(CMAKE_CXX_FLAGS_DEBUG "-ansi -pedantic -Wall -g")

add_subdirectory(src)
