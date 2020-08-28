#include "common/log/LogFile.h"

using namespace BearGame;


LogFile::LogFile(const std::string& logPrefix, off_t rollSize, 
            int flushInterval, int checkEveryN) 
    : m_logPrefix(logPrefix),
      m_rollSize(rollSize),
      m_flushInterval(flushInterval),
      m_checkEveryN(checkEveryN) {
    _RollFile();
}


LogFile::~LogFile() = default;

void LogFile::Append(const char* str, int size) {
    m_ptrFile->Append(str, size);
    if (m_ptrFile->GetWrittenBytes() > m_rollSize) {
        _RollFile();
        return;
    }

    ++ m_count;
    if (m_count >= m_checkEveryN) {
        m_count = 0;
        time_t now = ::time(NULL);
        time_t nowDay = now / kSecondsInDay * kSecondsInDay;
        if (nowDay != m_startDay) {
            _RollFile();
        } else if (now - m_lastFlush > m_flushInterval) {
            m_lastFlush = now;
            m_ptrFile->Flush();
        }
    }    

}

void LogFile::Flush() {
    m_ptrFile->Flush();
}

void LogFile::_RollFile() {
    time_t now = 0;
    auto fileName = _MakeLogFileName(&now);
    time_t start = now / kSecondsInDay * kSecondsInDay;
    if (now > m_lastRoll) {
        m_lastRoll = now;
        m_lastFlush = now;
        m_startDay = start;
        m_ptrFile.reset(new File(fileName, "ae"));
        m_ptrFile->SetBuffer(m_buffer, sizeof(m_buffer));
    }
}

std::string LogFile::_MakeLogFileName(time_t* now) {
    std::string fileName = m_logPrefix;
    fileName.reserve(m_logPrefix.size() + 64);
    
    struct tm tm_time;
    *now = time(NULL);
    ::localtime_r(now, &tm_time);
    char timeBuf[32]={NULL};
    ::strftime(timeBuf, sizeof(timeBuf), "_%Y%m%d", &tm_time);
    fileName += timeBuf;
    fileName += ".log";
    return fileName;
}