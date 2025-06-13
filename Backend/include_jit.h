#pragma once
struct IRNode;
void compile_jit(IRNode* node);
void execute(IRNode* node);
