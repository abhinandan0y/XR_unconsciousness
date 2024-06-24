# Makefile for compiling the game

# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Iinclude -Iinclude/glad
# Linker flags
LDFLAGS = -lglfw -ldl -lpthread

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
# Object files (excluding glad.o)
OBJECTS = $(filter-out $(OBJDIR)/glad.o, $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o))
# Additional object files
ADDITIONAL_OBJECTS = $(OBJDIR)/glad.o $(OBJDIR)/Camera.o $(OBJDIR)/Shader.o \
                    $(OBJDIR)/FrustumCulling.o $(OBJDIR)/LOD.o $(OBJDIR)/Mesh.o \
                    $(OBJDIR)/Model.o $(OBJDIR)/ResourceManager.o \
                    $(OBJDIR)/ScriptingSystem.o $(OBJDIR)/stb_image.o \
                    $(OBJDIR)/ThreadPool.o

# Executable name
EXECUTABLE = $(BINDIR)/game

# Default target
all: $(EXECUTABLE)

# Linking the executable
$(EXECUTABLE): $(OBJECTS) $(ADDITIONAL_OBJECTS) | $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Compiling source files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compiling glad.c to glad.o
$(OBJDIR)/glad.o: $(SRCDIR)/glad.c | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Creating directories if they don't exist
$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean target
clean:
	rm -rf $(BINDIR) $(OBJDIR)

# Phony targets
.PHONY: all clean

