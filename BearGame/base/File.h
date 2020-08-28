#ifndef BEARGAME_BASE_FILE_H
#define BEARGAME_BASE_FILE_H

#include <string>

#include "base/Noncopyable.h"

namespace BearGame {

class File : private Noncopyable {
public:
    File(const std::string& path, const std::string& mode);
    ~File();
public:
    void Flush();
    void Append(const char* str, const size_t size);
    off_t GetWrittenBytes() const { return m_writtenBytes; }
public:
    void SetBuffer(char* buf, size_t size);
private:
    size_t _Write(const char* str, const size_t size);
private:
    FILE* m_fp;
    off_t m_writtenBytes;
};


}

#endif