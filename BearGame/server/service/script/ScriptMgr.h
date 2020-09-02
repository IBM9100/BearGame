#ifndef BEARGAME_SERVER_COMMON_SCRIPTMGR_H
#define BEARGAME_SERVER_COMMON_SCRIPTMGR_H

#include "service/script/LuaScript.h"

namespace BearGame {

class ScriptMgr {
public:
    ScriptMgr();
    ~ScriptMgr() = default;
public:
    bool Init();
    void UnInit();
    bool Update();
private:
    LuaScript m_luaScript;
};

}

#endif