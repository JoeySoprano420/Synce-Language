CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)

AOTFrameEngine.exe: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ -lopengl32

clean:
	del /Q src\*.o AOTFrameEngine.exe
