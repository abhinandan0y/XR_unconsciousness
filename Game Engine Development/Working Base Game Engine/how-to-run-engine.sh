g++ -std=c++17 -Wall -Iinclude -Iinclude/glad -c src/glad.c -o obj/glad.o


g++ -std=c++17 -Wall -Iinclude -Iinclude/glad -c -o obj/Camera.o src/Camera.cpp
g++ -std=c++17 -Wall -Iinclude -Iinclude/glad -c -o obj/Shader.o src/Shader.cpp

g++ -std=c++17 -Wall -Iinclude -Iinclude/glad -c -o obj/FrustumCulling.o src/FrustumCulling.cpp
g++ -std=c++17 -Wall -Iinclude -Iinclude/glad -c -o obj/LOD.o src/LOD.cpp
g++ -std=c++17 -Wall -Iinclude -Iinclude/glad -c -o obj/Mesh.o src/Mesh.cpp
g++ -std=c++17 -Wall -Iinclude -Iinclude/glad -c -o obj/Model.o src/Model.cpp
g++ -std=c++17 -Wall -Iinclude -Iinclude/glad -c -o obj/ResourceManager.o src/ResourceManager.cpp
g++ -std=c++17 -Wall -Iinclude -Iinclude/glad -c -o obj/ScriptingSystem.o src/ScriptingSystem.cpp
g++ -std=c++17 -Wall -Iinclude -Iinclude/glad -c -o obj/stb_image.o src/stb_image.cpp
g++ -std=c++17 -Wall -Iinclude -Iinclude/glad -c -o obj/ThreadPool.o src/ThreadPool.cpp


mkdir -p bin  # This command ensures that the 'bin' directory exists

g++ -std=c++17 -Wall -Iinclude -Iinclude/glad \
    main.cpp \
    obj/Camera.o obj/FrustumCulling.o obj/LOD.o obj/Mesh.o \
    obj/Model.o obj/ResourceManager.o obj/ScriptingSystem.o \
    obj/Shader.o obj/stb_image.o obj/ThreadPool.o obj/glad.o \
    -o bin/game \
    -lglfw -ldl -lpthread
    
./bin/game
