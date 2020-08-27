#ifndef BEARGAME_SERVER_COMMON_LOG_LOGSTREAM_H
#define BEARGAME_SERVER_COMMON_LOG_LOGSTREAM_H

#include <string>
#include <cstring>
#include <algorithm>

#include "base/Noncopyable.h"

namespace BearGame {

const int kSmallBuffer = 4000;

template <int SIZE>
class LogBuffer : private Noncopyable {
public:
    LogBuffer() : m_ptrCur(m_data) { }
    ~LogBuffer() { }
public:
    void Append(const char* buf, size_t len) {
        memcpy(m_ptrCur, buf, len);
        m_ptrCur += len;
    }
    const char* GetData() const { return m_data; }
    int GetDataSize() const { return static_cast<int>(m_ptrCur - m_data); }
    char* GetCurPtr() { return m_ptrCur; }
    void Write(size_t len) { m_ptrCur += len; }
private:
    char m_data[SIZE];
    char* m_ptrCur;
};


class LogStream : private Noncopyable {
public:
    typedef LogBuffer<kSmallBuffer> Buffer;
    LogStream& operator<<(char v);
    LogStream& operator<<(const char* str);
    LogStream& operator<<(const std::string& str);

    LogStream& operator<<(int v);
    LogStream& operator<<(unsigned int v);
    LogStream& operator<<(unsigned long v);
    Buffer& GetBuffer() { return m_buffer; }
private:
    Buffer m_buffer;
};

}

#endif