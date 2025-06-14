#include "engine.h"
#include <sstream>
#include <iostream>
#include <regex>

Compiler::Compiler() {}

void Compiler::loadSource(const std::string& src) {
    sourceCode = src;
}

void Compiler::parse() {
    // Very simple example for parsing into AST
    root = std::make_shared<ASTNode>();
    root->type = "program";
    root->children.push_back(std::make_shared<ASTNode>(ASTNode{"const", "2+2"}));
}

void Compiler::optimize() {
    // Constant folding example
    std::regex constExpr("2\\s*\\+\\s*2");
    sourceCode = std::regex_replace(sourceCode, constExpr, "4");
}

void Compiler::generateIR() {
    // Simulate compiled IR
    Instruction i1{OP_LOAD, 0, 4, 0};
    Instruction i2{OP_PRINT, 0, 0, 0};
    ir.instructions = {i1, i2};

    std::string hash = "hash_of_4";
    cache.store(hash, ir);
}

const IRBlock& Compiler::getIR() const {
    return ir;
}

bool IRCache::exists(const std::string& hash) {
    return cache.find(hash) != cache.end();
}

void IRCache::store(const std::string& hash, const IRBlock& block) {
    cache[hash] = block;
}

IRBlock IRCache::load(const std::string& hash) {
    return cache.at(hash);
}
