CXX = g++
CXXFLAGS = -Iinclude -I/usr/include/lua5.3 -std=c++11
LDFLAGS = -lglfw -lGLEW -lGL -llua5.3 -ldl -lm

SRC_DIR = src
OBJ_DIR = obj

SOURCES = main.cpp \
          $(SRC_DIR)/ResourceManager.cpp \
          $(SRC_DIR)/ScriptingSystem.cpp \
          $(SRC_DIR)/FrustumCulling.cpp \
          $(SRC_DIR)/LOD.cpp \
		  $(SRC_DIR)/ThreadPool.cpp \
          stb_image.cpp

OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLE = OpenGLProject

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
