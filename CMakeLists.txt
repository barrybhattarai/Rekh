cmake_minimum_required(VERSION 3.22)
project(Kiran VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(include)
add_subdirectory(glm)
configure_file(config.h.in config.h)


add_executable(Kiran main.cc glad.c MainWindow.cpp)
target_link_libraries(Kiran glfw OpenGL glm::glm)
target_include_directories(Kiran PUBLIC ${PROJECT_BINARY_DIR})