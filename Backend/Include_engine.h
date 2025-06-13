#pragma once
#include "lexer.h"
#include "parser.h"
#include "ir.h"
#include "ast.h"
#include "codegen.h"
#include "jit.h"
#include "audio.h"
#include "render.h"
#include "fsm.h"
#include "pool.h"
#include "path.h"

// Entrypoint for full pipeline
void run_engine(int argc, char** argv);
