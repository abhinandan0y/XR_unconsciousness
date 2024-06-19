#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <unordered_map>
#include <memory>
#include <string>
#include <GL/glew.h>

class Texture {
public:
    Texture(const std::string& filePath);
    ~Texture();
    void bind() const;

private:
    GLuint textureID;
    void loadFromFile(const std::string& filePath);
};

class ResourceManager {
public:
    static std::shared_ptr<Texture> loadTexture(const std::string& name, const std::string& path);
    static std::shared_ptr<Texture> getTexture(const std::string& name);

private:
    static std::unordered_map<std::string, std::shared_ptr<Texture>> textures;
};

#endif // RESOURCE_MANAGER_HPP
