#ifndef SYNCE_LEXER_H
#define SYNCE_LEXER_H

#include <string>
#include <vector>

enum class TokenType {
Identifier,
Number,
Keyword,
Symbol,
Operator,
String,
EndOfFile,
Unknown
};

struct Token {
TokenType type;
std::string value;
int line;
int col;
};

std::vector<Token> lex_file(const std::string& filename);

#endif // SYNCE_LEXER_H
