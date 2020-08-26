#ifndef BEARGAME_SERVER_COMMON_CONFIG_CONFIG_H
#define BEARGAME_SERVER_COMMON_CONFIG_CONFIG_H

#include <memory>

#include "base/LuaParser.h"

namespace BearGame {


class Config {
public:
    Config();
    ~Config();
public:
    bool Init(const std::string& path);
public:
    uint32_t GetFps() const { return m_fps; }
public:
    template <typename T>
    bool GetValue(const std::string& key, T* value) {
        return m_ptrParser->GetValue(key, value);
    }
private:
    std::string m_configPath;
    std::unique_ptr<LuaParser> m_ptrParser;
    uint32_t m_fps;
};


}

#endif