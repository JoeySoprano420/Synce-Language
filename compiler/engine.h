#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

enum OpCode {
    OP_LOAD, OP_ADD, OP_SUB, OP_MUL, OP_DIV,
    OP_JMP, OP_JZ, OP_CALL, OP_RET, OP_PRINT
};

struct Instruction {
    OpCode op;
    int arg1;
    int arg2;
    int result;
};

struct ASTNode {
    std::string type;
    std::string value;
    std::vector<std::shared_ptr<ASTNode>> children;
};

struct IRBlock {
    std::vector<Instruction> instructions;
};

class IRCache {
public:
    bool exists(const std::string& hash);
    void store(const std::string& hash, const IRBlock& block);
    IRBlock load(const std::string& hash);

private:
    std::unordered_map<std::string, IRBlock> cache;
};

class Compiler {
public:
    Compiler();
    void loadSource(const std::string& src);
    void parse();
    void optimize(); // constant folding, loop unrolling, dead code
    void generateIR();
    const IRBlock& getIR() const;

private:
    std::string sourceCode;
    std::shared_ptr<ASTNode> root;
    IRBlock ir;
    IRCache cache;
};
