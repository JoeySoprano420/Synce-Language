#ifndef SYNCE_AST_H
#define SYNCE_AST_H

#include "../parser/parser.h"
#include <string>

std::string generate_hex_ast(const std::shared_ptr<ASTNode>& root);

#endif // SYNCE_AST_H
