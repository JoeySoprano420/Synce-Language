#include "shader.h"
#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include <iostream>

void ShaderProgram::loadFromFiles(const std::string& vertPath, const std::string& fragPath) {
    std::ifstream vFile(vertPath);
    std::ifstream fFile(fragPath);
    std::stringstream vStream, fStream;
    vStream << vFile.rdbuf();
    fStream << fFile.rdbuf();
    vertexSource = vStream.str();
    fragmentSource = fStream.str();
}

unsigned int ShaderProgram::compileShader(unsigned int type, const std::string& source) {
    const char* src = source.c_str();
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);
    return shader;
}

void ShaderProgram::compile() {
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexSource);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentSource);

    programId = glCreateProgram();
    glAttachShader(programId, vs);
    glAttachShader(programId, fs);
    glLinkProgram(programId);
}

void ShaderProgram::use() {
    glUseProgram(programId);
}
