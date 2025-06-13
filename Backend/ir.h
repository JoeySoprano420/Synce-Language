#ifndef SYNCE_IR_H
#define SYNCE_IR_H

#include "../parser/parser.h"
#include <string>

std::string generate_ir(const std::shared_ptr<ASTNode>& root);
void save_output(const std::string& content, const std::string& filename);

#endif // SYNCE_IR_H

#include "ir.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
std::string generate_ir(const std::shared_ptr<ASTNode>& root) {
	if (!root) {
		throw std::invalid_argument("AST root is null");
	}
	std::ostringstream ir_stream;
	// Here you would traverse the AST and generate IR code.
	// This is a placeholder implementation.
	ir_stream << "IR for AST node: " << root->to_string() << "\n";
	return ir_stream.str();
}

void save_output(const std::string& content, const std::string& filename) {
	std::ofstream file(filename
	);
	if (!file) {
		throw std::runtime_error("Could not open file for writing: " + filename);
	}
	file << content;
	if (!file) {
		throw std::runtime_error("Error writing to file: " + filename);
	}
	file.close();
	if (!file) {
		throw std::runtime_error("Error closing file: " + filename);
	}
	std::cout << "Output saved to " << filename << std::endl;
}

