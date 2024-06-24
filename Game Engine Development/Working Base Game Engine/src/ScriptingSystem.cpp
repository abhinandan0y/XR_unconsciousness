#include "ScriptingSystem.hpp"
#include <iostream>

void ScriptingSystem::ExecuteScript(const std::string& scriptName) {
    auto it = scripts.find(scriptName);
    if (it != scripts.end()) {
        // Execute the script (for simplicity, we'll just print the script)
        std::cout << "Executing script: " << it->second << std::endl;
    } else {
        std::cerr << "Script not found: " << scriptName << std::endl;
    }
}
