#pragma once
extern "C" {
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}
#include <string>
#include <iostream>

class ScriptingSystem {
public:
    ScriptingSystem();
    ~ScriptingSystem();
    void executeScript(const std::string& script);
private:
    lua_State* L;
};
