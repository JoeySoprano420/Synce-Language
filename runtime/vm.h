#pragma once
#include <vector>
#include <mutex>
#include "compiler/engine.h"

class VM {
public:
    VM();
    void load(const IRBlock& block);
    void execute();
    void executeAsync(); // JIT multi-threaded
    void hotSwap(const IRBlock& newBlock);

private:
    IRBlock ir;
    std::vector<int> registers;
    std::mutex execLock;
};
