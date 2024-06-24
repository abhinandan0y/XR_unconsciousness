#include "ResourceManager.hpp"
#include <iostream>

std::map<std::string, void*> ResourceManager::resources;

void ResourceManager::LoadResource(const std::string& name, const std::string& path) {
    // Load resource from path (for simplicity, we'll just simulate this)
    resources[name] = nullptr; // Assign the resource after loading
    std::cout << "Resource loaded: " << name << std::endl;
}

void* ResourceManager::GetResource(const std::string& name) {
    auto it = resources.find(name);
    if (it != resources.end()) {
        return it->second;
    } else {
        std::cerr << "Resource not found: " << name << std::endl;
        return nullptr;
    }
}
