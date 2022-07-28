cmake_minimum_required(VERSION 3.22)
project(Rekh VERSION 0.2)

set(CMAKE_CXX_STANDARD 17)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(include)
add_subdirectory(glm)
configure_file(config.h.in config.h)


add_executable(Rekh main.cc glad.c MainWindow.cpp Vbo.cpp Vao.cpp Shader.cpp program.cpp program.h)
target_link_libraries(Rekh glfw OpenGL glm::glm)
target_include_directories(Rekh PUBLIC ${PROJECT_BINARY_DIR})