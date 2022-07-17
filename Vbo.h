//
// Created by barry on 18/7/22.
//

#ifndef KIRAN_VBO_H
#define KIRAN_VBO_H

#include <glad/glad.h>

class Vbo {
private:
    unsigned int id{};
    GLenum type;

public:
    explicit Vbo(GLenum type = GL_ARRAY_BUFFER);

    void addData(GLsizei size, const void *data, GLenum use = GL_STATIC_DRAW) const;

    void bind() const;

    void unbind() const;

    void attribPointer(unsigned int location, int count, GLenum dataType, int stride,  unsigned  int offset,
                       bool normalize = false) const;

};


#endif //KIRAN_VBO_H
