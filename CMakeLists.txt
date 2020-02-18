# cmake ninimum version required
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name
project(LearnCpp)

# compile flags
set(CMAKE_CXX_FLAGS "-fPIC -ffast-math -pthread -fopenmp -g -std=c++11 -Wformat")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

# macro defines
add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)

# json
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/json/include/json/)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/json/lib/)

# gl
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gl/include/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gl/include/glfw/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gl/include/glfw/deps)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gl/include/imgui)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/gl/lib/)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/gl/src/ SRC_GL)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/gl/src/imgui/ SRC_IMGUI)

# common
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/common/include/)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/common/src/ SRC_COMMON)
add_library(common SHARED ${SRC_COMMON})

# log
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/log/glog/include/)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/log/glog/lib/)

# main
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/main/src SRC_MAIN)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/main/include/)

# executable file
set(TARGET LearnCpp)
add_executable(${TARGET} ${SRC_MAIN} ${SRC_GL} ${SRC_IMGUI} ${SRC_COMMON})

# lib link
target_link_libraries(${TARGET} jsoncpp glfw3 X11 GL dl glog)