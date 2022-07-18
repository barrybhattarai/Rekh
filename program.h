//
// Created by barry on 18/7/22.
//

#ifndef KIRAN_PROGRAM_H
#define KIRAN_PROGRAM_H


#include "Shader.h"

class Program {
public:
    Program();

    void checkProgram() const;

    void attachShader(const Shader &shader) const;

    void link() const;

    void deleteProgram() const;

    void useProgram() const;

    ~Program();

private:
    unsigned int id;

};


#endif //KIRAN_PROGRAM_H
