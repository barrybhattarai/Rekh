#include <iostream>
#include <glad/glad.h>
#include "MainWindow.h"
#include "Vbo.h"
#include "Vao.h"
#include "Shader.h"
#include "program.h"

float vertices[] = {
        -0.5f, -0.5f, 0.0f, 1.0, 0.0, 0.0,
        0.5f, -0.5f, 0.0f, 0.0, 1.0, 0.0,
        0.0f, 0.5f, 0.0f, 0.0, 0.0, 1.0
};

int main() {

    auto window = MainWindow(600, 600, "Kiran");
    window.makeContextCurrent();

    auto vertexShader = Shader(GL_VERTEX_SHADER, "/home/barry/CodeParty/bare/shaders/vert_shader.glsl");
    auto fragShader = Shader(GL_FRAGMENT_SHADER, "/home/barry/CodeParty/bare/shaders/frag_shader.glsl");


    auto program = Program();
    program.attachShader(vertexShader);
    program.attachShader(fragShader);
    program.link();


    auto vao = Vao();
    vao.bind();

    auto vbo = Vbo();
    vbo.addData(sizeof(vertices), vertices);
    vbo.attribPointer(0, 3, GL_FLOAT, 6 * sizeof(float), 0);
    vbo.attribPointer(1, 3, GL_FLOAT, 6 * sizeof(float), 3 * sizeof(float));

    vao.enableLocation(0);
    vao.enableLocation(1);
    program.useProgram();

    window.exec([]() -> void {
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    });

}

