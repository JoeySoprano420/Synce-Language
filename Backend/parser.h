#ifndef SYNCE_PARSER_H
#define SYNCE_PARSER_H

#include "../lexer/lexer.h"
#include <string>
#include <vector>
#include <memory>

enum class NodeType {
Program,
Statement,
Declaration,
Assignment,
FunctionCall,
Literal,
Identifier
};

struct ASTNode {
NodeType type;
std::string value;
std::vector<std::shared_ptr<ASTNode>> children;
};

std::shared_ptr<ASTNode> parse_tokens(const std::vector<Token>& tokens);

#endif // SYNCE_PARSER_H
