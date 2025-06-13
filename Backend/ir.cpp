#include "ir.h"
#include <fstream>
#include <sstream>
#include <iomanip>

static int next_ir_code = 700;  // Starting octal base code for IR

std::string generate_ir(const std::shared_ptr<ASTNode>& node) {
    std::ostringstream out;

    if (!node) return "";

    if (node->type == NodeType::Program) {
        for (auto& child : node->children) {
            out << generate_ir(child);
        }
    } else if (node->type == NodeType::Declaration) {
        out << "0" << std::oct << next_ir_code++ << " DECL " << node->value << "\n";
        out << generate_ir(node->children[0]);
    } else if (node->type == NodeType::Literal) {
        out << "0" << std::oct << next_ir_code++ << " LIT " << node->value << "\n";
    } else if (node->type == NodeType::Identifier) {
        out << "0" << std::oct << next_ir_code++ << " ID " << node->value << "\n";
    }

    return out.str();
}

void save_output(const std::string& content, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
    }
}
