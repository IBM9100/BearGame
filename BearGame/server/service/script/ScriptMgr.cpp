#include "service/script/ScriptMgr.h"
#include "service/script/LuaBinding.h"

using namespace BearGame;


ScriptMgr::ScriptMgr() 
    : m_luaScript() {

}

bool ScriptMgr::Init() {
    lua_State* state = m_luaScript.GetLuaState();
    RegisterGlobalFunc(state);

    if (!m_luaScript.DoFile("./BGScript/Boot.lua")) {
        LOG_ERROR << "";
    }

    m_luaScript.CallFunc("main");

    return true;
}

void ScriptMgr::UnInit() {

}

bool ScriptMgr::Update() {
    return true;
}


