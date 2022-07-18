//
// Created by barry on 18/7/22.
//

#include "glad/glad.h"
#include "MainWindow.h"
#include <config.h>
#include <string>
#include <sstream>
#include <iostream>

void keyPressCallback(GLFWwindow *_window, int key, int, int action, int) {
    if (key == GLFW_KEY_F && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(_window, true);
    }
}

void framebufferSizeCallback(GLFWwindow *, int width, int height) {
    glViewport(0, 0, width, height);
}


MainWindow::MainWindow(int width, int height, const char *title) : width(width), height(height), title(title) {
    initialize();
    std::stringstream ss;
    ss << this->title << " v" << KIRAN_VERSION_MAJOR << '.' << KIRAN_VERSION_MINOR;
    window = glfwCreateWindow(this->width, this->height, ss.str().c_str(), nullptr, nullptr);
    glfwSetKeyCallback(window, keyPressCallback);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
}

void MainWindow::exec(const std::function<void()> &loop) {
    while (!glfwWindowShouldClose(window)) {
        loop();
        glfwSwapBuffers(window);
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
    gladLoadGLLoader(reinterpret_cast<GLADloadproc >(glfwGetProcAddress));

}

void MainWindow::initialize() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


}






