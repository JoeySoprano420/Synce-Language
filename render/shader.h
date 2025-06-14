#pragma once
#include <string>

class ShaderProgram {
public:
    void loadFromFiles(const std::string& vertPath, const std::string& fragPath);
    void compile();
    void use();

private:
    unsigned int programId;
    std::string vertexSource;
    std::string fragmentSource;

    unsigned int compileShader(unsigned int type, const std::string& source);
};
