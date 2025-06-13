CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I. -Ilexer -Iparser -Iir -Iast -Icodegen -Ijit

SRC = syncec.cpp \
      lexer/lexer.cpp \
      parser/parser.cpp \
      ir/ir.cpp \
      ast/ast.cpp \
      codegen/codegen.cpp \
      jit/jit.cpp

OUT = bin/syncec

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT) output/tmp.* output/*.bin output/*.asm output/*.oct output/*.hex
