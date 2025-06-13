#include "jit.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>

std::vector<unsigned char> jit_compile(const std::string& nasm_code) {
    const std::string asm_file = "output/tmp.s";
    const std::string obj_file = "output/tmp.o";
    const std::string bin_file = "output/program.bin";

    std::ofstream asm_out(asm_file);
    asm_out << nasm_code;
    asm_out.close();

    std::string assemble_cmd = "nasm -f elf32 " + asm_file + " -o " + obj_file;
    std::string link_cmd = "ld -m elf_i386 " + obj_file + " -o " + bin_file;

    int result = std::system(assemble_cmd.c_str());
    result |= std::system(link_cmd.c_str());

    std::ifstream bin_in(bin_file, std::ios::binary);
    std::vector<unsigned char> bin((std::istreambuf_iterator<char>(bin_in)), {});
    return bin;
}

void save_binary(const std::vector<unsigned char>& bin, const std::string& filename) {
    std::ofstream out(filename, std::ios::binary);
    for (auto byte : bin) {
        out.put(static_cast<char>(byte));
    }
    out.close();
}
