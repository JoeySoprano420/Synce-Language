# Synce-Language

🧠 SYNCE COMPILER — MAXIMUM OVERVIEW
🚀 Purpose
A full-stack language toolchain for Synce, a high-level yet low-level-aware programming language that:

Compiles from human-readable Synce syntax

Translates into Octal IR + Hex AST

Generates real NASM Assembly

Executes via JIT into a native .bin

⚙️ Compiler Design (syncec)
Lexer: Pattern-based (regex)

Parser: Instruction-oriented

IR Generator: Emits .synce.ir.oct

AST Builder: Emits .synce.ast.hex

NASM Codegen: Emits .asm file

Binary JIT Layer: Live execution + cache



Toolchain Pack (Deliverable)
syncec.bat (Windows) / syncec.sh (Linux/macOS)

synce_stdlib/ core modules and math

synce.tmLanguage.json for VSCode syntax

synce.ir.template for IR → NASM mapping

synce.ast.template for Hex AST encoding

Full compiler source in C/NASM/Python (your choice)



📦 File & Directory Structure

synce_compiler/
├── syncec.cpp                    ← Main entry point
├── Makefile                      ← Build system
├── build.sh / build.bat          ← Build scripts
│
├── lexer/                        ← Tokenizer
│   ├── lexer.h
│   └── lexer.cpp
│
├── parser/                       ← AST builder
│   ├── parser.h
│   └── parser.cpp
│
├── ir/                           ← Octal IR generator
│   ├── ir.h
│   └── ir.cpp
│
├── ast/                          ← Hex AST dumper
│   ├── ast.h
│   └── ast.cpp
│
├── codegen/                      ← NASM codegen
│   ├── codegen.h
│   └── codegen.cpp
│
├── jit/                          ← JIT binary compiler
│   ├── jit.h
│   └── jit.cpp
│
├── examples/                     ← Demo source files
│   └── test.snc
│
├── output/                       ← All compilation artifacts
│   ├── *.oct   (Octal IR)
│   ├── *.ast.hex (Hex AST)
│   ├── *.asm   (NASM)
│   └── *.bin   (Executable)




🔄 Compilation Flow

examples/test.snc
    ↓
[Lexer] → Token Stream
    ↓
[Parser] → Abstract Syntax Tree (AST)
    ↓
[IR Generator] → Octal Intermediate Representation (.oct)
    ↓
[AST Dumper] → Hex Tree Dump (.ast.hex)
    ↓
[Code Generator] → NASM Assembly (.asm)
    ↓
[JIT Compiler] → Native Binary (.bin)




🧩 Language Features Supported (V1)

| Feature        | Example                        | Compiled As              |
| -------------- | ------------------------------ | ------------------------ |
| Variable Decl  | `let x = 42;`                  | `DECL x`, `LIT 42` in IR |
| Literals       | `42`, `"hello"`                | `LIT` or `STR` in IR     |
| Identifiers    | `x`, `y`                       | `ID x` in IR             |
| AST Node Types | `Program`, `Decl`, `Lit`, `ID` | Dumped as `0xA0X`        |
| NASM           | Assembly output                | Real `mov`, `int 0x80`   |




💻 Outputs

| File Type  | Description             | Example                |
| ---------- | ----------------------- | ---------------------- |
| `.oct`     | Octal IR                | `0714 DECL x`          |
| `.ast.hex` | Hexadecimal AST Dump    | `0xA00 NODE x`         |
| `.asm`     | NASM Assembly Code      | `mov eax, 42`          |
| `.bin`     | Native Linux Executable | ELF x86 (i386, via ld) |




🛠 Build System

🧾 Makefile
Compiles all .cpp files

Output binary: bin/syncec

Run with .snc input



🐧 build.sh

#!/bin/bash
make -C "$(dirname "$0")"




🪟 build.bat

@echo off
make




🧪 Example Input File
📄 examples/test.snc

let x = 42;
let y = 13;




💥 Sample IR Output (program.oct)

01314 DECL x
01315 LIT 42
01316 DECL y
01317 LIT 13




🌲 Sample AST Output (program.ast.hex)

0xA00 NODE program
0xA01 NODE x
0xA02 NODE 42
0xA03 NODE y
0xA04 NODE 13




🔧 Sample NASM Output (program.asm)

section .data
msg db 'Compiled Synce Program', 0xA, 0

section .text
global _start
_start:
    ; declare x
    mov eax, 0
    mov eax, 42
    ; declare y
    mov eax, 0
    mov eax, 13
    mov ebx, 0
    mov eax, 1
    int 0x80




🧬 Execution Requirements

| Tool        | Purpose                    |
| ----------- | -------------------------- |
| `nasm`      | Assemble `.s` → `.o`       |
| `ld`        | Link `.o` → `.bin`         |
| `make`      | Build orchestrator         |
| Linux (x86) | Target platform for `.bin` |




🧠 Future Expansion (Planned)

Expressions & arithmetic

Conditions, branches

Function declarations & calls

Memory access (alloc, free)

Namespaces & modules

Shader/instruction textures

Real octal/hex symbol table



# AOTFrameEngine

A solid-state, AOT + JIT, full-frame compilation engine for high-performance, real-time, immersive multimedia software.  
**Features:** Finite State Machines, Node Pooling, SIMD optimization, NASM-level audio/video, OpenGL/Vulkan ready.

## Build

- Open `AOTFrameEngine.sln` in Visual Studio 2022 (Windows x64), or  
- `make` (with MinGW/MSYS2), or  
- Compile `src/*.cpp` with your preferred C++17+ toolchain

## Run

`AOTFrameEngine.exe [script.octir]`

---

**Modules:**
- src/lexer.cpp, parser.cpp, ir.cpp, ast.cpp, codegen.cpp, jit.cpp, fsm.cpp, pool.cpp, audio.cpp, render.cpp, path.cpp, main.cpp
- include/*.h

---





