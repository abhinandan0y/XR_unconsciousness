#include "ScriptingSystem.hpp"

ScriptingSystem::ScriptingSystem() {
    L = luaL_newstate();
    luaL_openlibs(L);
}

ScriptingSystem::~ScriptingSystem() {
    lua_close(L);
}

void ScriptingSystem::executeScript(const std::string& script) {
    if (luaL_dofile(L, script.c_str()) != LUA_OK) {
        std::cerr << lua_tostring(L, -1) << std::endl;
        lua_pop(L, 1);  // Remove error message from stack
    }
}
