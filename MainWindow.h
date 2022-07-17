//
// Created by barry on 18/7/22.
//

#ifndef BARE_MAINWINDOW_H
#define BARE_MAINWINDOW_H

#include <GLFW/glfw3.h>

class MainWindow {
public:
    MainWindow(int width, int height, const char *title);

    void exec();

    void terminate();
    ~MainWindow();
    void makeContextCurrent();

private:
    GLFWwindow *window;
    int width, height;
    const char* title;

    static void initialize();



};


#endif //BARE_MAINWINDOW_H
