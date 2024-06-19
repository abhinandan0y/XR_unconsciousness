CXX = g++
CXXFLAGS = -Iinclude -I/usr/include/lua5.3 -std=c++11
LDFLAGS = -lglfw -lGLEW -lGL -llua5.3 -ldl -lm

SRC = main.cpp src/ResourceManager.cpp src/ScriptingSystem.cpp src/stb_image.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = OpenGLProject

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: clean
