#ifndef BEARGAME_SERVER_COMMON_LOG_LOGGING_H
#define BEARGAME_SERVER_COMMON_LOG_LOGGING_H

#include "common/log/LogStream.h"

namespace BearGame {

class Logger {
public:
    enum LogLevel {
        TRACE, DEBUG, INFO, WARN, ERROR, FATAL, NUM_LOG_LEVELS,
    };
public:
    class SourceFile {
    public:
        template <int N>
        SourceFile(const char (&arr)[N]) 
            : data(arr), 
              size(N - 1) {
            const char* slash = strrchr(data, '/');
            if (slash) {
                data = slash + 1;
                size -= static_cast<int>(data - arr);
            }
        }
        explicit SourceFile(const char* fileName) : data(fileName) {
            const char* slash = strrchr(fileName, '/');
            if (slash) {
                data = slash + 1;
            }
            size = static_cast<int>(strlen(data));
        }
    public:
        const char* data;
        int size;
    };
public:
    Logger(SourceFile fileName, int line, const char* funcName, LogLevel level);
    ~Logger();
    LogStream& GetStream() { return m_impl.m_stream; }
public:
    static LogLevel GetLogLevel();
    static void SetLogLevel(LogLevel level);

    typedef void (*OutputFunc)(const char* msg, int size);
    typedef void (*FlushFunc)();
    
    static void SetOutputFunc(OutputFunc func);
    static void SetFlushFunc(FlushFunc func);
private:
    class Impl {
    public:
        typedef Logger::LogLevel LogLevel;
        Impl(LogLevel level, const SourceFile& fileName, int line, const char* funcName);
        void FormatTime();
        void LineEnd();
    public:
        LogStream m_stream;
        LogLevel m_level;
        SourceFile m_fileName;
        int m_line;
        const char* m_funcName;
    };
    Impl m_impl;
};

inline LogStream& operator<<(LogStream& o, const Logger::SourceFile& fileName) {
    o.GetBuffer().Append(fileName.data, fileName.size);
    return o;
}

extern Logger::LogLevel g_logLevel;

inline Logger::LogLevel Logger::GetLogLevel() {
    return g_logLevel;
}

// Fixme!!!
#define LOG_TRACE if (Logger::GetLogLevel() <= Logger::TRACE)\
    Logger(__FILE__, __LINE__, __func__, Logger::TRACE).GetStream()
#define LOG_DEBUG if (Logger::GetLogLevel() <= Logger::TRACE)\
    Logger(__FILE__, __LINE__, __func__, Logger::DEBUG).GetStream()
#define LOG_INFO if (Logger::GetLogLevel() <= Logger::TRACE)\
    Logger(__FILE__, __LINE__, __func__, Logger::INFO).GetStream()
#define LOG_WARN if (Logger::GetLogLevel() <= Logger::TRACE)\
    Logger(__FILE__, __LINE__, __func__, Logger::WARN).GetStream()
#define LOG_ERROR if (Logger::GetLogLevel() <= Logger::TRACE)\
    Logger(__FILE__, __LINE__, __func__, Logger::ERROR).GetStream()
}

#endif