cmake_minimum_required(VERSION 3.19.2)
project(sfmath)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_library(sfmath STATIC ${SOURCES})

target_include_directories(sfmath PUBLIC include/)
target_precompile_headers(sfmath PRIVATE "include/sfmath/pch.h")

if(MSVC)
    target_sources(sfmath PRIVATE src/pch.cpp)
endif()

# Using Other precompiled headers
# Define SFMATH_USE_PCH
# Define SFMATH_PCH_DIR="path/to/pch.h"