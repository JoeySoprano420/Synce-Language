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

CXX = g++
CXXFLAGS = -std=c++20 -O3 -Wall -Wextra -fopenmp
LDFLAGS = -lGL -lglfw -lGLEW -lm -ldl -pthread

SRC = $(wildcard core/*.cpp) \
      $(wildcard render/*.cpp) \
      $(wildcard audio/*.cpp) \
      $(wildcard optimize/*.cpp) \
      $(wildcard ai/*.cpp) \
      $(wildcard runtime/*.cpp) \
      $(wildcard compiler/*.cpp)

HDR = $(wildcard core/*.h) \
      $(wildcard render/*.h) \
      $(wildcard audio/*.h) \
      $(wildcard optimize/*.h) \
      $(wildcard ai/*.h) \
      $(wildcard runtime/*.h) \
      $(wildcard compiler/*.h)

OBJ = $(SRC:.cpp=.o)

TARGET = vacu_runtime

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)

rebuild: clean all
