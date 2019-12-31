# cmake ninimum version required
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name
project(LearnCpp)

#compile flags
set(CMAKE_CXX_FLAGS "-fPIC -ffast-math -pthread -fopenmp -g -std=c++11 -Wformat")

#include files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/json/)

#lib files
set(CMKAE_LIBRARY_PATH "./lib")
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

# source files
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)

# executable file
set(TARGET LearnCpp)
add_executable(${TARGET} ${SRC_LIST})

target_link_libraries(${TARGET} jsoncpp)