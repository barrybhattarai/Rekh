cmake_minimum_required(VERSION 3.22)
project(bare)

set(CMAKE_CXX_STANDARD 17)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(include)

add_executable(bare main.cc glad.c)
target_link_libraries(bare glfw OpenGL)