#include "service/script/LuaBinding.h"
#include "common/log/Logging.h"

using namespace luabridge;
using namespace BearGame;

int BearGame::RegisterGlobalFunc(lua_State* state) {
    getGlobalNamespace(state)
        .addFunction("CGetWorkDir", ScriptExport::GetWorkDir)
        .addFunction("CLog", ScriptExport::LuaLog);

    return 0;
}


std::string ScriptExport::GetWorkDir() {
    std::string res;
    char* buffer = getcwd(nullptr, 0);
    if (buffer) {
        res = buffer;
    }
    free(buffer);
    return res;
}

void ScriptExport::LuaLog(std::string fileName, int line, std::string funcName, int level, std::string content) {
    Logger(Logger::SourceFile(fileName.c_str()), line, funcName.c_str(), Logger::LogLevel(level)).GetStream() << content;
}
