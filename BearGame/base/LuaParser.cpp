#include "base/LuaParser.h"

using namespace BearGame;


LuaParser::LuaParser() 
    : m_luaState(luaL_newstate()) {
    luaL_openlibs(m_luaState);
}


LuaParser::~LuaParser() {
    lua_close(m_luaState);
    m_luaState = nullptr;
}

bool LuaParser::DoString(const std::string& script) {
    if (luaL_dostring(m_luaState, script.c_str()) != 0) {
        return false;
    }
    return true;
}

bool LuaParser::DoFile(const std::string& path) {
    if (luaL_dofile(m_luaState, path.c_str()) != 0) {
        return false;
    }
    return true;
}
