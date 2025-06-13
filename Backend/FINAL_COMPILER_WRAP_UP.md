| Part         | File            | Function                    |
| ------------ | --------------- | --------------------------- |
| Lexer        | `lexer.cpp/h`   | Token generation            |
| Parser       | `parser.cpp/h`  | AST construction            |
| IR Generator | `ir.cpp/h`      | Octal IR                    |
| AST          | `ast.cpp/h`     | Hex Tree                    |
| Codegen      | `codegen.cpp/h` | Emit NASM                   |
| JIT          | `jit.cpp/h`     | Hot execution               |
| Audio        | `audio.cpp/h`   | Procedural DSP              |
| Video        | `render.cpp/h`  | Vectorized pixel pipeline   |
| Engine       | `main.cpp`      | Entrypoint and orchestrator |
