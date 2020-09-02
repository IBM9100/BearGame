#include "service/script/LuaScript.h"

using namespace BearGame;

LuaScript::LuaScript() 
    : m_luaState(luaL_newstate()) {
    luaL_openlibs(m_luaState);
}

LuaScript::~LuaScript() {
    if (m_luaState) {
        lua_close(m_luaState);
        m_luaState = nullptr;
    }
}


bool LuaScript::DoFile(const std::string& path) {
    if (luaL_dofile(m_luaState, path.c_str()) != 0) {
        return false;
    }
    return true;
}