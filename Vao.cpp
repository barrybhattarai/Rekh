//
// Created by barry on 18/7/22.
//

#include "Vao.h"
#include <glad/glad.h>

Vao::Vao() {
    glGenVertexArrays(1, &id);
}

void Vao::bind() const {
    glBindVertexArray(id);

}

void Vao::unbind() const {
    glBindVertexArray(0);
}
