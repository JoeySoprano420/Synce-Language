#ifndef SYNCE_JIT_H
#define SYNCE_JIT_H

#include <string>
#include <vector>

std::vector<unsigned char> jit_compile(const std::string& nasm_code);
void save_binary(const std::vector<unsigned char>& bin, const std::string& filename);

#endif // SYNCE_JIT_H
