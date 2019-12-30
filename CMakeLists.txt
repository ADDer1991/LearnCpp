# cmake ninimum version required
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name
project(LearnCpp)

# source files
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)

# executable file
SET(TARGET LearnCpp)
add_executable(${TARGET} ${SRC_LIST})