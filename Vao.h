//
// Created by barry on 18/7/22.
//

#ifndef KIRAN_VAO_H
#define KIRAN_VAO_H


class Vao {
public:
    Vao();
    void bind() const;

    void unbind() const;
private:
    unsigned int id{};
};


#endif //KIRAN_VAO_H
