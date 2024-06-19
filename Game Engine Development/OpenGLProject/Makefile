# Makefile
CXX = g++
CXXFLAGS = -Wall -std=c++11
LIBS = -lglfw -lGLEW -lGL
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = opengl_example

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(OBJ) $(EXEC)
