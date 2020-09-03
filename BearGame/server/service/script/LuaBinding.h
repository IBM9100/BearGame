#ifndef BEARGAME_SERVER_SERVICE_LUABINDDING_H
#define BEARGAME_SERVER_SERVICE_LUABINDDING_H

#include <unistd.h>

#include "base/LuaHeader.h"


namespace BearGame {

    int RegisterGlobalFunc(lua_State* state);

    namespace ScriptExport {
        std::string GetWorkDir();
        void LuaLog(std::string fileName, int line, std::string funcName, int level, std::string content);
    }

}

#endif