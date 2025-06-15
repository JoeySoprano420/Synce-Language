#include <fstream>
#include <cstdlib>
#include "engine.h"

void writeNASM(const IRBlock& ir, const std::string& filename) {
    std::ofstream out(filename);
    out << "section .text\\nglobal _start\\n_start:\\n";
    for (const auto& instr : ir.instructions) {
        switch (instr.op) {
            case OP_LOAD:
                out << "mov eax, " << instr.arg2 << "\\n";
                break;
            case OP_PRINT:
                out << "mov ebx, eax\\n"; // simulate print
                break;
            default:
                break;
        }
    }
    out << "mov eax, 1\\nint 0x80\\n";
    out.close();
}

void compileToExecutable(const IRBlock& ir, const std::string& outputPath) {
    writeNASM(ir, "program.asm");
    system("nasm -f elf32 program.asm -o program.o");
    system("ld -m elf_i386 program.o -o output.exe");
    system(("mv output.exe " + outputPath).c_str());
}
