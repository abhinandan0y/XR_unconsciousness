# Set the C++ compiler
CXX = g++

# Set the C++ compiler flags
CXXFLAGS = -std=c++11 -Iinclude -I/usr/include/lua5.3 -Iinclude/glad

# Set the linker flags
LDFLAGS = -L/usr/lib/x86_64-linux-gnu -Wl,-rpath=/usr/lib/x86_64-linux-gnu

# Set the libraries to link against
LIBS = -lglfw -lGL -lassimp -llua5.3 -ldl -lm -ldraco

# Additional libraries specific to your project
GLAD_LIB = -Linclude/glad -lglad
STB_LIB = -Linclude/stb_image -lstb_image

# Set the object files to link
OBJS = obj/Camera.o obj/FrustumCulling.o obj/LOD.o obj/Mesh.o \
       obj/Model.o obj/ResourceManager.o obj/ScriptingSystem.o \
       obj/Shader.o obj/ThreadPool.o obj/glad.o  # Add glad.o here

# Set the target executable file
TARGET = bin/OpenGLProject

# Set the rule to build the target executable file
$(TARGET): $(OBJS)
	mkdir -p bin
	$(CXX) $(LDFLAGS) $(OBJS) -o $@ $(LIBS) $(GLAD_LIB) $(STB_LIB)

# Set the rule to compile the source files into object files
obj/%.o: src/%.cpp
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile glad (assuming glad.c is in your src folder)
obj/glad.o: src/glad.c
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean the build artifacts
.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -rf bin
