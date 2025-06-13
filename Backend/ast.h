#ifndef SYNCE_AST_H
#define SYNCE_AST_H

#include "../parser/parser.h"
#include <string>

std::string generate_hex_ast(const std::shared_ptr<ASTNode>& root);

#endif // SYNCE_AST_H

#include "ast.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>

std::string generate_hex_ast(const std::shared_ptr<ASTNode>& root) {
	if (!root) {
		throw std::invalid_argument("Root node is null");
	}
	std::ostringstream oss;
	oss << "AST Hex Representation:\n";
	// Traverse the AST and generate hex representation
	std::function<void(const std::shared_ptr<ASTNode>&, int)> traverse;
	traverse = [&](const std::shared_ptr<ASTNode>& node, int depth) {
		if (!node) return;
		oss << std::string(depth * 2, ' ') << "Node Type: " << node->type << ", Value: ";
		if (node->value.has_value()) {
			oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(node->value.value());
		} else {
			oss << "null";
		}
		oss << "\n";
		for (const auto& child : node->children) {
			traverse(child, depth + 1);
		}
	};
	traverse(root, 0);
	return oss.str();
}

