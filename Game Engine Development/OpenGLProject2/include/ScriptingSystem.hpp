#ifndef SCRIPTING_SYSTEM_HPP
#define SCRIPTING_SYSTEM_HPP

#include <lua.hpp>
#include <string>

class ScriptingSystem {
public:
    ScriptingSystem();
    ~ScriptingSystem();
    void executeScript(const std::string& script);

private:
    lua_State* L;
};

#endif // SCRIPTING_SYSTEM_HPP
