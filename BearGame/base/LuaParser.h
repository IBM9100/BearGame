#ifndef BEARGAME_BASE_LUAPARSER_H
#define BEARGAME_BASE_LUAPARSER_H

extern "C" {
    #include "lua/lua.h"
    #include "lua/lualib.h"
    #include "lua/lauxlib.h"
}

#include "LuaBridge/LuaBridge.h"
#include "base/Noncopyable.h"

namespace BearGame {

using luabridge::LuaRef;

class LuaParser : private Noncopyable {
public:
    LuaParser();
    ~LuaParser();
public:
    bool DoString(const std::string& script);
    bool DoFile(const std::string& path);
public:
    template <typename T>
    bool GetValue(const std::string& key, T* value) {
        LuaRef ref = luabridge::getGlobal(m_luaState, key.c_str());
        if (ref.isNil()) {
            return false;
        }
        *value = ref.cast<T>();
        return true;
    }
private:
    lua_State* m_luaState;
};

}

#endif