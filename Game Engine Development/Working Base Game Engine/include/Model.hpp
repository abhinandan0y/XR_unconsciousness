#pragma once
#include <string>
#include <vector>
#include "Mesh.hpp"
#include "Shader.hpp"

class Model {
public:
    Model(std::string path);
    void Draw(Shader shader);

private:
    std::vector<Mesh> meshes;
    std::string directory;
    void loadModel(std::string path);
    void processNode(void* node, const void* scene);
    Mesh processMesh(void* mesh, const void* scene);
};
