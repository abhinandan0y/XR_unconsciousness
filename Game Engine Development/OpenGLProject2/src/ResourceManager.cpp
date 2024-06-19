#include "ResourceManager.hpp"
#include "stb_image.h"
#include <iostream>

std::unordered_map<std::string, std::shared_ptr<Texture>> ResourceManager::textures;

Texture::Texture(const std::string& filePath) {
    loadFromFile(filePath);
}

Texture::~Texture() {
    glDeleteTextures(1, &textureID);
}

void Texture::bind() const {
    glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::loadFromFile(const std::string& filePath) {
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    int width, height, nrChannels;
    unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);
    if (data) {
        GLenum format;
        if (nrChannels == 1)
            format = GL_RED;
        else if (nrChannels == 3)
            format = GL_RGB;
        else if (nrChannels == 4)
            format = GL_RGBA;

        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cerr << "Failed to load texture: " << filePath << std::endl;
    }
    stbi_image_free(data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

std::shared_ptr<Texture> ResourceManager::loadTexture(const std::string& name, const std::string& path) {
    auto texture = std::make_shared<Texture>(path);
    textures[name] = texture;
    return texture;
}

std::shared_ptr<Texture> ResourceManager::getTexture(const std::string& name) {
    return textures[name];
}
