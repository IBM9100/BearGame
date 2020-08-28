#include "common/log/Logging.h"

#include "base/Clock.h"

using namespace BearGame;

namespace BearGame {

const char* LogLevelName[Logger::NUM_LOG_LEVELS] = {
    "TRACE",
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR",
    "FATAL",
};

void defaultOutput(const char* msg, int size) {
    ::fwrite(msg, 1, size, stdout);
}

void defaultFlush() {
    ::fflush(stdout);
}

Logger::LogLevel g_logLevel = Logger::INFO;
Logger::OutputFunc g_logOutputFunc = defaultOutput;
Logger::FlushFunc g_logFlushFunc = defaultFlush;

}


Logger::Logger(SourceFile fileName, int line, const char* funcName, LogLevel level)
    : m_impl(level, fileName, line, funcName) {
}

Logger::~Logger() {
    m_impl.LineEnd();
    auto& buf = m_impl.m_stream.GetBuffer();
    g_logOutputFunc(buf.GetData(), buf.GetDataSize());
    if (m_impl.m_level == FATAL) {
        g_logFlushFunc();
    }
}

void Logger::SetLogLevel(LogLevel level) {
    g_logLevel = level;
}

void Logger::SetOutputFunc(OutputFunc func) {
    g_logOutputFunc = func;
}

void Logger::SetFlushFunc(FlushFunc func) {
    g_logFlushFunc = func;
}


Logger::Impl::Impl(LogLevel level, const SourceFile& fileName, int line, const char* funcName)
    : m_stream(),
      m_level(level),
      m_fileName(fileName),
      m_line(line),
      m_funcName(funcName) {
    FormatTime();
    m_stream << "[" << LogLevelName[m_level] << "]";
    m_stream << "[" << m_fileName << "]";
    m_stream << "[" << m_line << "]";
    m_stream << "[" << m_funcName << "] ";

}

void Logger::Impl::FormatTime() {
    auto time = Clock::instance().Now();
    auto s = static_cast<time_t>(time / 1000000);
    struct tm tm_time;
    ::localtime_r(&s, &tm_time);
    char timeBuf[32]={NULL};
    snprintf(timeBuf, sizeof(timeBuf), "[%4d-%02d-%02d %02d:%02d:%02d] ",
        tm_time.tm_year + 1900, tm_time.tm_mon + 1, tm_time.tm_mday,
        tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec);
    m_stream << timeBuf;
}


void Logger::Impl::LineEnd() {
    m_stream << '\n';
}