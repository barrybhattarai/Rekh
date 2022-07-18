//
// Created by barry on 18/7/22.
//

#include <iostream>
#include "program.h"
#include "glad/glad.h"
#include "Shader.h"

Program::Program() {
    id = glCreateProgram();
}

void Program::checkProgram() const {
    int success;
    char infoLog[512];
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(id, 512, nullptr, infoLog);
        std::cerr << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
}

void Program::attachShader(const Shader &shader) const {
    glAttachShader(id, shader.getId());
}

void Program::link() const {
    glLinkProgram(id);
    checkProgram();
}

void Program::deleteProgram() const {
    glDeleteProgram(id);
}

void Program::useProgram() const {
    glUseProgram(id);
}

Program::~Program() {
    deleteProgram();
}

