
#include <glad/glad.h>
#include "MainWindow.h"
#include "Vbo.h"
#include "Vao.h"
#include "Shader.h"
#include "program.h"
#include <vector>
#include <cmath>

float vertices[] = {
        -0.5f, 0.5f, 0.0f, 1.0, 0.0, 0.0,
        -0.5f, -0.5f, 0.0f, 0.0, 1.0, 0.0,
        0.5f, -0.5f, 0.0f, 0.0, 0.0, 1.0,
        0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f
};


int main() {
    const float PI = atanf(1) * 4;

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

    std::vector<float> verts;
    float r = 0.5;
    float steps = 2 * PI / 100;
    float angle = 0;
    while(angle < 2* PI){
        float x = cosf(angle)/2;
        float y = sinf(angle)/2;
        verts.push_back(x);
        verts.push_back(y);
        verts.push_back(0);
        angle+= steps;
    }

    auto vbo = Vbo();
    vbo.addData(verts.size()* sizeof(float ), verts.data());
    vbo.attribPointer(0, 3, GL_FLOAT, 3 * sizeof(float), 0);
    vbo.attribPointer(1, 3, GL_FLOAT, 6 * sizeof(float), 3 * sizeof(float));

    vao.enableLocation(0);
//    vao.enableLocation(1);
    program.useProgram();
    window.exec([=]() -> void {
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 100);

    });

}

