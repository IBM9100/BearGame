#ifndef BEARGAME_SERVER_SERVICE_LUABINDDING_H
#define BEARGAME_SERVER_SERVICE_LUABINDDING_H

#include <unistd.h>

#include "base/LuaHeader.h"

#include "common/log/Logging.h"

namespace BearGame {

    namespace ScriptExport {
        std::string GetWorkDir() {
            std::string res;
            char* buffer = getcwd(nullptr, 0);
            if (buffer) {
                res = buffer;
            }
            return res;
        }
        void LuaLog(std::string fileName, int line, std::string funcName, int level, std::string content) {
            Logger(Logger::SourceFile(fileName.c_str()), line, funcName.c_str(), Logger::LogLevel(level)).GetStream() << content;
        }

    }


    using namespace luabridge;
    using namespace ScriptExport;

    int RegisterGlobalFunc(lua_State* state) {
        getGlobalNamespace(state)
            .addFunction("CGetWorkDir", GetWorkDir)
            .addFunction("CLog", LuaLog);

        return 0;
    }



}

#endif