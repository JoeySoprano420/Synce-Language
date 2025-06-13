#include <iostream>
#include "lexer/lexer.h"
#include "parser/parser.h"
#include "ir/ir.h"
#include "ast/ast.h"
#include "codegen/codegen.h"
#include "jit/jit.h"

int main(int argc, char** argv) {
if (argc < 2) {
std::cerr << "Usage: syncec <source.synce>\n"
return 1;
}

const char* filename = argv[1];
std::cout << "[SYNCE] Compiling: " << filename << std::endl;

auto tokens = lex_file(filename);
auto ast = parse_tokens(tokens);
auto ir = generate_ir(ast);
auto hex_ast = generate_hex_ast(ast);
auto nasm_code = generate_nasm(ir);
auto binary = jit_compile(nasm_code);

save_output(ir, "output/program.oct");
save_output(hex_ast, "output/program.ast.hex");
save_output(nasm_code, "output/program.asm");
save_binary(binary, "output/program.bin");

std::cout << "[SYNCE] Compilation Complete." << std::endl;
return 0;
}
