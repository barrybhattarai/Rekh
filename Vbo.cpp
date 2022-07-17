//
// Created by barry on 18/7/22.
//

#include "Vbo.h"

Vbo::Vbo(GLenum type) : type(type) {
    glGenBuffers(1, &id);

}


void Vbo::bind() const {
    glBindBuffer(type, id);
}

void Vbo::addData(GLsizei size, const void *data, GLenum use) const {
    bind();
    glBufferData(type, size, data, use);
}

void Vbo::attribPointer(unsigned int location, int count, GLenum dataType, int stride,
                        unsigned  int offset, bool normalize) const {
    glVertexAttribPointer(location, count, dataType, normalize, stride, reinterpret_cast<const void *>(offset));
}

void Vbo::unbind() const {
    glBindBuffer(type, 0);
}
