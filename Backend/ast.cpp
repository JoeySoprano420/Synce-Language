#include "ast.h"
#include <sstream>
#include <iomanip>

static int next_ast_code = 0xA00;

std::string generate_hex_ast(const std::shared_ptr<ASTNode>& node) {
    std::ostringstream out;

    if (!node) return "";

    out << std::hex << std::uppercase << "0x" << next_ast_code++ << " NODE ";
    out << node->value << "\n";

    for (auto& child : node->children) {
        out << generate_hex_ast(child);
    }

    if (node->children.empty()) {
        out << std::hex << std::uppercase << "0x" << next_ast_code++ << " LEAF " << node->value << "\n";
	}out << std::hex << std::uppercase << "0x" << next_ast_code++ << " ENDNODE " << node->value << "\n";

    return out.str();
}

std::string generate_hex_ast(const std::vector<std::shared_ptr<ASTNode>>& nodes) {
    std::ostringstream out;
    for (const auto& node : nodes) {
        out << generate_hex_ast(node);
    }
    return out.str();
}

std::string generate_hex_ast(const std::shared_ptr<ASTNode>& node, const std::string& prefix) {
    std::ostringstream out;
    if (!node) return "";
    out << prefix << std::hex << std::uppercase << "0x" << next_ast_code++ << " NODE " << node->value << "\n";
    for (auto& child : node->children) {
        out << generate_hex_ast(child, prefix + "  ");
    }
    if (node->children.empty()) {
        out << prefix << std::hex << std::uppercase << "0x" << next_ast_code++ << " LEAF " << node->value << "\n";
    }
    out << prefix << std::hex << std::uppercase << "0x" << next_ast_code++ << " ENDNODE " << node->value << "\n";
    return out.str();
}

std::string generate_hex_ast(const std::vector<std::shared_ptr<ASTNode>>& nodes, const std::string& prefix) {
    std::ostringstream out;
    for (const auto& node : nodes) {
        out << generate_hex_ast(node, prefix);
    }
    return out.str();
}

std::string generate_hex_ast(const std::shared_ptr<ASTNode>& node, int& code) {
    std::ostringstream out;
    if (!node) return "";
    out << std::hex << std::uppercase << "0x" << code++ << " NODE " << node->value << "\n";
    for (auto& child : node->children) {
        out << generate_hex_ast(child, code);
    }
    if (node->children.empty()) {
        out << std::hex << std::uppercase << "0x" << code++ << " LEAF " << node->value << "\n";
    }
    out << std::hex << std::uppercase << "0x" << code++ << " ENDNODE " << node->value << "\n";
    return out.str();
}

std::string generate_hex_ast(const std::vector<std::shared_ptr<ASTNode>>& nodes, int& code) {
    std::ostringstream out;
    for (const auto& node : nodes) {
        out << generate_hex_ast(node, code);
    }
    return out.str();
}

std::string generate_hex_ast(const std::shared_ptr<ASTNode>& node, const std::string& prefix, int& code) {
    std::ostringstream out;
    if (!node) return "";
    out << prefix << std::hex << std::uppercase << "0x" << code++ << " NODE " << node->value << "\n";
    for (auto& child : node->children) {
        out << generate_hex_ast(child, prefix + "  ", code);
    }
    if (node->children.empty()) {
        out << prefix << std::hex << std::uppercase << "0x" << code++ << " LEAF " << node->value << "\n";
    }
    out << prefix << std::hex << std::uppercase << "0x" << code++ << " ENDNODE " << node->value << "\n";
    return out.str();
}

