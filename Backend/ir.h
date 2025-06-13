#ifndef SYNCE_IR_H
#define SYNCE_IR_H

#include "../parser/parser.h"
#include <string>

std::string generate_ir(const std::shared_ptr<ASTNode>& root);
void save_output(const std::string& content, const std::string& filename);

#endif // SYNCE_IR_H
