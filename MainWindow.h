//
// Created by barry on 18/7/22.
//

#ifndef BARE_MAINWINDOW_H
#define BARE_MAINWINDOW_H

#include <GLFW/glfw3.h>
#include <functional>

class MainWindow {
public:
    MainWindow(int width, int height, const char *title);

    void exec(const std::function<void()> &loop);

    void terminate();

    ~MainWindow();

    void makeContextCurrent();

    friend void keyPressCallback(GLFWwindow *, int key, int scancode, int action, int mods);

    friend void framebufferSizeCallback(GLFWwindow* window, int width, int height);

private:
    GLFWwindow *window;
    int width, height;

    const char *title;

    static void initialize();


};


#endif //BARE_MAINWINDOW_H
