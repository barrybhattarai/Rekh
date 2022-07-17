//
// Created by barry on 18/7/22.
//

#include "glad/glad.h"
#include "MainWindow.h"

MainWindow::MainWindow(int width, int height, const char *title) : width(width), height(height), title(title) {
    initialize();
    window = glfwCreateWindow(this->width, this->height, this->title, nullptr, nullptr);
}

void MainWindow::exec() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void MainWindow::terminate() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

MainWindow::~MainWindow() {
    terminate();
}

void MainWindow::makeContextCurrent() {
    glfwMakeContextCurrent(window);
}

void MainWindow::initialize() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    gladLoadGLLoader(reinterpret_cast<GLADloadproc >(glfwGetProcAddress));


}
