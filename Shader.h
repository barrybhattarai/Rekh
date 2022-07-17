//
// Created by barry on 18/7/22.
//

#ifndef KIRAN_SHADER_H
#define KIRAN_SHADER_H
#include <glad/glad.h>
#include <string>

class Shader {
public:
    Shader(GLenum type, const std::string& filePath);
    static std::string readFileAsString(const std::string& filePath) ;

     void checkShader() const;
     [[nodiscard]] unsigned int getId() const;
private:
    GLenum type;
    unsigned  int id;

    void compile() const;



};


#endif //KIRAN_SHADER_H
