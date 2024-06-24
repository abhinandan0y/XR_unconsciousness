#pragma once
#include <string>
#include <map>

class ResourceManager {
public:
    static void LoadResource(const std::string& name, const std::string& path);
    static void* GetResource(const std::string& name);

private:
    static std::map<std::string, void*> resources;
};
