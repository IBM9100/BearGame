#include "base/File.h"

#include <assert.h>
#include <errno.h>

using namespace BearGame;

File::File(const std::string& path, const std::string& mode)
    : m_fp(::fopen(path.c_str(), mode.c_str())) {
    assert(m_fp);
}

 File::~File() {
     ::fclose(m_fp);
 }

 void File::Flush() {
     ::fflush(m_fp);
 }

void File::Append(const char* str, const size_t size) {
    size_t n = _Write(str, size);
    size_t remain = size - n;
    while (remain > 0) {
        size_t x = _Write(str + n, remain);
        if (x == 0) {
            int err = ferror(m_fp);
            if (err) {
                fprintf(stderr, "File::Append() failed %d\n", err);
            }
            break;
        }
        remain = size - x;
    }
    m_writtenBytes += size;
}

size_t File::_Write(const char* str, const size_t size) {
    return ::fwrite_unlocked(str, 1, size, m_fp);
}

void File::SetBuffer(char* buf, size_t size) {
    setvbuf(m_fp, buf, _IOFBF, size);
}
