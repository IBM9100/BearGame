#ifndef BEARGAME_SERVER_COMMON_LOG_LOGGING_H
#define BEARGAME_SERVER_COMMON_LOG_LOGGING_H

#include "common/log/LogStream.h"

namespace BearGame {

class LogStream;

class Logger {
public:
    enum LogLevel {
        TRACE, DEBUG, INFO, WARN, ERROR, FATAL, NUM_LOG_LEVELS,
    };
public:
    Logger(const char* fileName, int line);
    ~Logger();
public:
    static LogLevel LogLevel();
    // static void SetLogLevel(LogLevel level);
    LogStream& stream() { return m_impl.m_stream; }
private:
    class Impl {
    public:
        // typedef Logger::LogLevel LogLevel;
        Impl(int line);
        void FormatTime();
        void Finish();
        
        LogStream m_stream;

        int m_line;
    };
    Impl m_impl;
};


#define LOG_TRACE \
    BearGame::Logger(__FILE__, __LINE__).stream()

}

#endif