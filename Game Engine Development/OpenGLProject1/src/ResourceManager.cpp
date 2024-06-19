#include "ResourceManager.hpp"
#include "stb_image.h"



std::unordered_map<std::string, std::shared_ptr<Texture>> ResourceManager::textures;

Texture::Texture(const std::string& path) {
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    unsigned char* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    stbi_image_free(data);
}

Texture::~Texture() {
    glDeleteTextures(1, &id);
}

void Texture::bind() const {
    glBindTexture(GL_TEXTURE_2D, id);
}

std::shared_ptr<Texture> ResourceManager::loadTexture(const std::string& name, const std::string& path) {
    auto texture = std::make_shared<Texture>(path);
    textures[name] = texture;
    return texture;
}

std::shared_ptr<Texture> ResourceManager::getTexture(const std::string& name) {
    return textures.at(name);
}
