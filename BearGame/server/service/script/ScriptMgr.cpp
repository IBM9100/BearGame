#include "service/script/ScriptMgr.h"

using namespace BearGame;


ScriptMgr::ScriptMgr() 
    : m_luaScript() {

}

bool ScriptMgr::Init() {
    m_luaScript.DoFile("./BearNet/boot.lua");
    m_luaScript.CallFunc("main");
    return true;
}

void ScriptMgr::UnInit() {

}

bool ScriptMgr::Update() {
    return true;
}


