#include "codegen.h"
#include <sstream>
#include <vector>
#include <string>
#include <regex>

std::vector<std::string> split_lines(const std::string& input) {
    std::vector<std::string> lines;
    std::istringstream stream(input);
    std::string line;
    while (std::getline(stream, line)) {
        lines.push_back(line);
    }
    return lines;
}

std::string generate_nasm(const std::string& ir) {
    std::ostringstream out;
    out << "section .data\n";
    out << "msg db 'Compiled Synce Program', 0xA, 0\n";
    out << "section .text\n";
    out << "global _start\n";
    out << "_start:\n";

    auto lines = split_lines(ir);
    for (const auto& line : lines) {
        std::smatch match;
        if (std::regex_match(line, match, std::regex("0[0-9]+ DECL (\\w+)"))) {
            std::string var = match[1];
            out << "    ; declare " << var << "\n";
            out << "    mov eax, 0\n";
        } else if (std::regex_match(line, match, std::regex("0[0-9]+ LIT (\\d+)"))) {
            std::string val = match[1];
            out << "    mov eax, " << val << "\n";
        } else if (std::regex_match(line, match, std::regex("0[0-9]+ ID (\\w+)"))) {
            std::string id = match[1];
            out << "    ; use identifier " << id << "\n";
        }
    }

    out << "    mov ebx, 0\n";
    out << "    mov eax, 1\n";
    out << "    int 0x80\n";

    return out.str();
}
