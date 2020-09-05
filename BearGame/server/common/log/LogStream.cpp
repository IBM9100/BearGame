#include "common/log/LogStream.h"
#include "base/Convert.h"

using namespace BearGame;


LogStream& LogStream::operator<<(char v) {
    m_buffer.Append(&v, 1);
    return *this;
}

LogStream& LogStream::operator<<(const char* str) {
    if (str) {
        m_buffer.Append(str, strlen(str));
    } else {
        m_buffer.Append("(null)", 6);
    }
    return *this;
}

LogStream& LogStream::operator<<(const std::string& str) {
    m_buffer.Append(str.c_str(), str.size());
    return *this;
}

LogStream& LogStream::operator<<(int v) {
    size_t n = Convert(m_buffer.GetCurPtr(), v);
    m_buffer.Write(n);
    return *this;
}

LogStream& LogStream::operator<<(unsigned int v) {
    size_t n = Convert(m_buffer.GetCurPtr(), v);
    m_buffer.Write(n);
    return *this;
}

LogStream& LogStream::operator<<(unsigned long v) {
    size_t n = Convert(m_buffer.GetCurPtr(), v);
    m_buffer.Write(n);
    return *this;
}