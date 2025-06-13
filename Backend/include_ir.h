#pragma once
#include <string>
struct IRNode {
    std::string opcode;
    // ... operands
};
IRNode* compile_to_ir(const char* path);
void fold_constants(IRNode* ir);
void unroll_loops(IRNode* ir);
