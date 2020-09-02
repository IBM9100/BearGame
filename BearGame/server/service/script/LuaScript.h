#ifndef BEARGAME_SERVER_COMMON_LUASCRIPT_H
#define BEARGAME_SERVER_COMMON_LUASCRIPT_H

#include "base/LuaHeader.h"
#include "common/log/Logging.h"

namespace BearGame {

using luabridge::LuaRef;
using luabridge::getGlobal;

class LuaScript {
public:
    LuaScript();
    ~LuaScript();
public:
    bool DoFile(const std::string& path);
    lua_State* GetLuaState() const { return m_luaState; }
public:
    template <typename ...PARAM>
    bool CallFunc(const std::string& funcName, PARAM... params);
private:
    lua_State* m_luaState;
};

template <typename ...PARAM>
bool LuaScript::CallFunc(const std::string& funcName, PARAM... params) {
    bool result = false;
    LuaRef ref = getGlobal(m_luaState, funcName.c_str());
    
    if (!ref.isFunction()) {
        LOG_ERROR << funcName << " is not a function.";
        goto Exit0;
    }
    ref(params...);
    
    result = true;
Exit0:
    return result;
}

}

#endif