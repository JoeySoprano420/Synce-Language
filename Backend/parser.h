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

#include "parser.h"
#include <stdexcept>
std::shared_ptr<ASTNode> parse_tokens(const std::vector<Token>& tokens) {
	if (tokens.empty()) {
		throw std::runtime_error("No tokens to parse");
	}
	auto root = std::make_shared<ASTNode>();
	root->type = NodeType::Program;
	for (const auto& token : tokens) {
		auto node = std::make_shared<ASTNode>();
		node->value = token.value;
		switch (token.type) {
			case TokenType::Keyword:
				node->type = NodeType::Declaration;
				break;
			case TokenType::Identifier:
				node->type = NodeType::Identifier;
				break;
			case TokenType::Literal:
				node->type = NodeType::Literal;
				break;
			case TokenType::Operator:
				node->type = NodeType::Assignment;
				break;
			case TokenType::FunctionCall:
				node->type = NodeType::FunctionCall;
				break;
			default:
				node->type = NodeType::Statement;
				break;
		}
		root->children.push_back(node);
	}
	return root;
}

