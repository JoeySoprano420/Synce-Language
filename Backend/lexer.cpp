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

#include "lexer.h"
#include <fstream>
#include <sstream>
#include <cctype>
#include <stdexcept>
std::vector<Token> lex_file(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		throw std::runtime_error("Could not open file: " + filename);
	}
	std::vector<Token> tokens;
	std::string line;
	int line_number = 0;
	while (std::getline(file, line)) {
		line_number++;
		int col_number = 0;
		for (size_t i = 0; i < line.size(); ++i) {
			char c = line[i];
			col_number++;
			if (std::isspace(c)) {
				continue; // Skip whitespace
			} else if (std::isalpha(c)) {
				std::string identifier;
				while (i < line.size() && (std::isalnum(line[i]) || line[i] == '_')) {
					identifier += line[i++];
				}
				--i; // Adjust for the loop increment
				tokens.push_back({TokenType::Identifier, identifier, line_number, col_number});
			} else if (std::isdigit(c)) {
				std::string number;
				while (i < line.size() && std::isdigit(line[i])) {
					number += line[i++];
				}
				--i; // Adjust for the loop increment
				tokens.push_back({TokenType::Number, number, line_number, col_number});
			} else if (c == '"') {
				std::string str;
				i++; // Skip the opening quote
				while (i < line.size() && line[i] != '"') {
					str += line[i++];
				}
				if (i < line.size()) { // Skip the closing quote
					i++;
				}
				tokens.push_back({TokenType::String, str, line_number, col_number});
			} else if (std::ispunct(c)) {
				tokens.push_back({TokenType::Symbol, std::string(1, c), line_number, col_number});
			} else {
				tokens.push_back({TokenType::Unknown, std::string(1, c), line_number, col_number});
			}
		}
	}
	tokens.push_back({TokenType::EndOfFile, "", line_number, col_number});
	return tokens;
}

#include "lexer.h"
#include <iostream>
int main() {
	try {
		std::vector<Token> tokens = lex_file("example.synce");
		for (const auto& token : tokens) {
			std::cout << "Token
				Type: " << static_cast<int>(token.type) 
				<< ", Value: '" << token.value 
				<< "', Line: " << token.line 
				<< ", Column: " << token.col << std::endl;
		}
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}

