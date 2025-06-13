// ========== include/engine.h ==========
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

void run_engine(int argc, char** argv);


// ========== src/main.cpp ==========
#include "engine.h"

int main(int argc, char** argv) {
    run_engine(argc, argv);
    return 0;
}


// ========== include/fsm.h ==========
#pragma once

typedef void (*FSMHandler)(void*);

struct FSMNode {
    int state;
    FSMHandler handler;
};

void transition(FSMNode* node, int new_state, FSMHandler handler);


// ========== src/fsm.cpp ==========
#include "fsm.h"

void transition(FSMNode* node, int new_state, FSMHandler handler) {
    node->state = new_state;
    node->handler = handler;
}


// ========== include/pool.h ==========
#pragma once
#include <vector>

template<typename T>
class NodePool {
    std::vector<T*> pool;
public:
    T* acquire() {
        if (pool.empty()) return new T();
        T* obj = pool.back();
        pool.pop_back();
        return obj;
    }
    void release(T* node) {
        pool.push_back(node);
    }
};


// ========== include/audio.h ==========
#pragma once

enum WaveType { SINE, SQUARE, NOISE };

struct SoundIRNode {
    WaveType type;
    float frequency;
    float modulation;
};

float generate_wave(const SoundIRNode& node, float time);
void process_audio_frame(float time);


// ========== src/audio.cpp ==========
#include "audio.h"
#include <cmath>
#include <cstdlib>

float generate_wave(const SoundIRNode& node, float time) {
    switch(node.type) {
        case SINE: return std::sin(time * node.frequency);
        case SQUARE: return std::sin(time * node.frequency) > 0 ? 1.0f : -1.0f;
        case NOISE: return (float)std::rand() / RAND_MAX * 2.0f - 1.0f;
        default: return 0.0f;
    }
}

void process_audio_frame(float time) {
    SoundIRNode node = {SINE, 440.0f, 0.0f};
    float val = generate_wave(node, time);
    // Output val to audio buffer
}


// ========== include/render.h ==========
#pragma once

void init_render();
void render_frame();


// ========== src/render.cpp ==========
#include "render.h"
#include <GL/gl.h>

void init_render() {
    // OpenGL context setup assumed done externally
}

void render_frame() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Render draw calls go here
}


// ========== include/ir.h ==========
#pragma once
#include <string>

struct IRNode {
    std::string opcode;
    // Add operands as needed
};

IRNode* compile_to_ir(const char* path);
void fold_constants(IRNode* ir);
void unroll_loops(IRNode* ir);


// ========== include/jit.h ==========
#pragma once
struct IRNode;

void compile_jit(IRNode* node);
void execute(IRNode* node);


// ========== Makefile ==========
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude
SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)

AOTFrameEngine.exe: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ -lopengl32

clean:
	del /Q src\*.o AOTFrameEngine.exe


// ========== README.md ==========
# AOTFrameEngine

A full-frame, solid-state AOT+JIT compiler framework with FSM, audio synthesis, OpenGL rendering, and IR-based logic pipeline.

## Compile:
- Open `AOTFrameEngine.sln` in Visual Studio
- Or run `make` (if using MinGW)

## Run:
`AOTFrameEngine.exe [script.octir]`

Modules are stubbed out and extensible. Populate lexer, parser, IR logic, and real asset pipelines to expand.

---

*More files for lexer, parser, codegen, path navigation can be added next if you confirm.*
