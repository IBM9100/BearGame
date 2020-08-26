#include "common/config/Config.h"


using namespace BearGame;

Config::Config() 
    : m_ptrParser(new LuaParser()) {

}

Config::~Config() {

}


bool Config::Init(const std::string& path) {
    bool result = false;
    
    if (!m_ptrParser->DoFile(path)) {
        printf("Error dofile");
        goto Exit0;
    }

    if (!m_ptrParser->GetValue("fps", &m_fps)) {
        printf("Error GetValue");

        goto Exit0;
    }

    result = true;
Exit0:
    return result;

}


