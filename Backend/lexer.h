#include "lexer.h"
#include <fstream>
#include <sstream>
#include <cctype>
#include <unordered_set>

static std::unordered_set<std::string> keywords = {
"let", "val", "func", "procedure", "return", "if", "else", "while",
"break", "continue", "await", "sync", "throw", "catch", "try"
};

std::vector<Token> lex_file(const std::string& filename) {
std::vector<Token> tokens;
std::ifstream file(filename);
std::string line;
int line_num = 0;

while (std::getline(file, line)) {
++line_num;
for (size_t i = 0; i < line.size(); ++i) {
char ch = line[i];
if (std::isspace(ch)) continue;

if (std::isalpha(ch)) {
std::string ident;
size_t col = i;
while (i < line.size() && (std::isalnum(line[i]) || line[i] == '_')) {
ident += line[i++];
}
--i;
tokens.push_back({
keywords.count(ident) ? TokenType::Keyword : TokenType::Identifier,
ident, line_num, (int)col
});
} else if (std::isdigit(ch)) {
std::string num;
size_t col = i;
while (i < line.size() && std::isdigit(line[i])) {
num += line[i++];
}
--i;
tokens.push_back({ TokenType::Number, num, line_num, (int)col });
} else if (ch == '"') {
std::string str;
size_t col = i;
++i;
while (i < line.size() && line[i] != '"') {
str += line[i++];
}
tokens.push_back({ TokenType::String, str, line_num, (int)col });
} else {
std::string sym(1, ch);
tokens.push_back({ TokenType::Symbol, sym, line_num, (int)i });
}
}
}

tokens.push_back({ TokenType::EndOfFile, "", line_num + 1, 0 });
return tokens;
}
