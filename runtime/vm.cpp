#include "vm.h"
#include <thread>
#include <iostream>

VM::VM() {
    registers.resize(16, 0);
}

void VM::load(const IRBlock& block) {
    ir = block;
}

void VM::execute() {
    for (const auto& instr : ir.instructions) {
        switch (instr.op) {
            case OP_LOAD: registers[instr.arg1] = instr.arg2; break;
            case OP_PRINT: std::cout << "VM OUT: " << registers[instr.arg1] << "\\n"; break;
            default: break;
        }
    }
}

void VM::executeAsync() {
    std::thread([this]() {
        std::lock_guard<std::mutex> lock(execLock);
        execute();
    }).join();
}

void VM::hotSwap(const IRBlock& newBlock) {
    std::lock_guard<std::mutex> lock(execLock);
    ir = newBlock;
}
