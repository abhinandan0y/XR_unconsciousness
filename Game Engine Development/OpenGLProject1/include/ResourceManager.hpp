#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include <GL/glew.h>
#include <stb_image.h>

class Texture {
public:
    GLuint id;
    int width, height, channels;

    Texture(const std::string& path);
    ~Texture();
    void bind() const;
};

class ResourceManager {
public:
    static std::shared_ptr<Texture> loadTexture(const std::string& name, const std::string& path);
    static std::shared_ptr<Texture> getTexture(const std::string& name);

private:
    static std::unordered_map<std::string, std::shared_ptr<Texture>> textures;
};
