#ifndef SYNCE_CODEGEN_H
#define SYNCE_CODEGEN_H

#include "../parser/parser.h"
#include <string>

std::string generate_nasm(const std::string& ir);

#endif // SYNCE_CODEGEN_H
