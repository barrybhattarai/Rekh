//
// Created by barry on 18/7/22.
//

#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>

Shader::Shader(GLenum type, const std::string &filePath) : type(type) {
    id = glCreateShader(type);
    auto source = readFileAsString(filePath);
    auto c_str = source.c_str();
    glShaderSource(id, 1, &c_str, nullptr);
    compile();
    checkShader();
}

void Shader::compile() const {
    glCompileShader(id);
}

std::string Shader::readFileAsString(const std::string &filePath) {
    auto file = std::ifstream(filePath);
    if (file.fail()) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        std::cerr << file.exceptions();
        std::exit(1);
    }
    std::stringstream ss;
    ss << file.rdbuf();
    file.close();
    return ss.str();

}

void Shader::checkShader() const {
    int success;
    char infoLog[512];
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(id, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

unsigned int Shader::getId() const {
    return id;
}

void Shader::deleteShader() const {
    glDeleteShader(id);
}

Shader::~Shader() {
    deleteShader();
}
