#pragma once
#include <string>
#include <unordered_map>

class ScriptingSystem {
public:
    void ExecuteScript(const std::string& scriptName);
private:
    std::unordered_map<std::string, std::string> scripts;
};
