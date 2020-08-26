#ifndef BEARGAME_SERVER_COMMON_LOG_LOGSTREAM_H
#define BEARGAME_SERVER_COMMON_LOG_LOGSTREAM_H

#include <string>
#include <cstring>

#include "base/Noncopyable.h"

namespace BearGame {

template <int SIZE>
class Buffer : private Noncopyable {
public:
    Buffer() : m_ptrCur(m_data) { }
    ~Buffer() { }
public:
    void Append(const char* buf, size_t len) {
        memcpy(m_ptrCur, buf, len);
        m_ptrCur += len;
    }
    const char* data() const { return m_data; }
    int length() const { return static_cast<int>(m_ptrCur - m_data); }
private:
    char m_data[SIZE];
    char* m_ptrCur;
};


class LogStream : private Noncopyable {
public:
    LogStream& operator<<(const std::string& str) {
        m_buffer.Append(str.c_str(), str.size());
        m_buffer.Append("\n", 1);
        return *this;
    }
    const Buffer<4000>& buffer() const { return m_buffer; }

private:
    Buffer<4000> m_buffer;
};

}

#endif