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

std::vector<unsigned char> load_binary(const std::string& filename\) {
    std::ifstream in(filename, std::ios::binary);
    if (!in) {
        throw std::runtime_error("Failed to open binary file: " + filename);
    }
    return std::vector<unsigned char>((std::istreambuf_iterator<char>(in)), {});
}

std::string read_file(const std::string& filename) {
	std
		::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + filename);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
	return buffer.str();
}

void write_file(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file for writing: " + filename);
    }
    file << content;
    file.close();
}

std::string get_temp_filename() {
    static int counter = 0;
    return "output/tmp_" + std::to_string(counter++) + ".s";
}

std::string get_temp_obj_filename() {
    static int counter = 0;
    return "output/tmp_" + std::to_string(counter++) + ".o";
}

std::string get_temp_bin_filename() {
    static int counter = 0;
    return "output/tmp_" + std::to_string(counter++) + ".bin";
}

std::string get_temp_asm_filename() {
    static int counter = 0;
    return "output/tmp_" + std::to_string(counter++) + ".asm";
}

std::string get_temp_txt_filename() {
    static int counter = 0;
    return "output/tmp_" + std::to_string(counter++) + ".txt";
}

std::string get_temp_json_filename() {
    static int counter = 0;
    return "output/tmp_" + std::to_string(counter++) + ".json";
}

std::string get_temp_log_filename() {
    static int counter = 0;
    return "output/tmp_" + std::to_string(counter++) + ".log";
}


