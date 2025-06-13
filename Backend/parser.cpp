#include "parser.h"
#include <iostream>

static size_t current = 0;
static std::vector<Token> toks;

static Token peek() {
return current < toks.size() ? toks[current] : Token{TokenType::EndOfFile, "", 0, 0};
}

static Token advance() {
return toks[current++];
}

static bool match(TokenType type) {
if (peek().type == type) {
advance();
return true;
}
return false;
}

static std::shared_ptr<ASTNode> parse_expression();

static std::shared_ptr<ASTNode> parse_statement() {
Token t = peek();
if (t.type == TokenType::Keyword && t.value == "let") {
advance(); // let
Token ident = advance(); // variable name
advance(); // =
auto expr = parse_expression();

auto node = std::make_shared<ASTNode>();
node->type = NodeType::Declaration;
node->value = ident.value;
node->children.push_back(expr);
return node;
}
return nullptr;
}

static std::shared_ptr<ASTNode> parse_expression() {
Token t = advance();
auto node = std::make_shared<ASTNode>();
if (t.type == TokenType::Number || t.type == TokenType::String) {
node->type = NodeType::Literal;
node->value = t.value;
} else if (t.type == TokenType::Identifier) {
node->type = NodeType::Identifier;
node->value = t.value;
}
return node;
}

std::shared_ptr<ASTNode> parse_tokens(const std::vector<Token>& tokens) {
toks = tokens;
current = 0;

auto root = std::make_shared<ASTNode>();
root->type = NodeType::Program;
root->value = "program"

while (peek().type != TokenType::EndOfFile) {
auto stmt = parse_statement();
if (stmt) {
root->children.push_back(stmt);
} else {
advance(); // skip unknown token
}
}

return root;
}
