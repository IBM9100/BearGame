#ifndef BEARGAME_SERVER_COMMON_LOG_LOGFILE_H
#define BEARGAME_SERVER_COMMON_LOG_LOGFILE_H

#include <memory>

#include "base/File.h"

namespace BearGame {

class LogFile : private Noncopyable {
public:
    LogFile(const std::string& logPrefix, off_t rollSize = 1024 * 1024 * 1024, 
            int flushInterval = 3, int checkEveryN = 1024);
    ~LogFile();
public:
    void Append(const char* str, int size);
    void Flush();
private:
    void _RollFile();
    std::string _MakeLogFileName(time_t* now);
private:
    const std::string m_logPrefix;
    const off_t m_rollSize;
    const int m_flushInterval;
    const int m_checkEveryN;
    int m_count;
    time_t m_startDay;
    time_t m_lastRoll;
    time_t m_lastFlush;
    std::unique_ptr<File> m_ptrFile;
    
    char m_buffer[64 * 1024];
    const static int kSecondsInDay = 60*60*24;
};

}

#endif