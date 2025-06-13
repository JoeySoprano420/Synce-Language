#include "ast.h"
#include <sstream>
#include <iomanip>

static int next_ast_code = 0xA00;

std::string generate_hex_ast(const std::shared_ptr<ASTNode>& node) {
std::ostringstream out;

if (!node) return ""

out << std::hex << std::uppercase << "0x" << next_ast_code++ << " NODE "
out << node->value << "\n"

for (auto& child : node->children) {
out << generate_hex_ast(child);
}

return out.str();
}
