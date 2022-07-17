#include <iostream>
#include <glad/glad.h>
#include "MainWindow.h"
#include "Vbo.h"
#include "Vao.h"

const char *V_SOURCE = R"(
#version 420 core
layout (location=0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
out vec3 color;
void main(){
gl_Position =  vec4(aPos, 1.0);
color = aColor;
})";

const char *F_SOURCE = R"(
#version 420 core
in vec3 color;
out vec4 fragColor;
void main(){
fragColor = vec4(color, 1.0);
})";

void checkShader(unsigned int shader) {
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void checkProgram(unsigned int program) {
    int success;
    char infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::cerr << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
}

float vertices[] = {
        -0.5f, -0.5f, 0.0f, 1.0, 0.0, 0.0,
        0.5f, -0.5f, 0.0f, 0.0, 1.0, 0.0,
        0.0f, 0.5f, 0.0f, 0.0, 0.0, 1.0
};

int main() {

    auto window = MainWindow(600, 600, "Kiran");
    window.makeContextCurrent();

//
//    //OPENGL SECTION
    auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &V_SOURCE, nullptr);
    glCompileShader(vertexShader);
    checkShader(vertexShader);
    auto fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &F_SOURCE, nullptr);
    glCompileShader(fragShader);
    checkShader(fragShader);

    auto shader = glCreateProgram();
    glAttachShader(shader, vertexShader);
    glAttachShader(shader, fragShader);
    glLinkProgram(shader);
    checkProgram(shader);

    auto vao = Vao();
    vao.bind();
    auto vbo = Vbo();
    vbo.addData(sizeof(vertices), vertices);
    vbo.attribPointer(0, 3, GL_FLOAT, 6 * sizeof(float), 0);
    vbo.attribPointer(1, 3, GL_FLOAT, 6 * sizeof(float), 3 * sizeof(float));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glUseProgram(shader);
    window.exec([=]()->void{
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    });

}


//
//    unsigned int vbo;
//    glGenBuffers(1, &vbo);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
//                          reinterpret_cast<const void *>(3 * sizeof(float)));
//
//
//    glUseProgram(shader);