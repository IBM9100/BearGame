#include "common/log/Logging.h"

using namespace BearGame;

Logger::Logger(const char* fileName, int line)
    : m_impl(line) {
}

Logger::~Logger() {
    const Buffer<4000>& buf = stream().buffer();
    size_t n = fwrite(buf.data(), 1, buf.length(), stdout);
    (void)n;
}

Logger::Impl::Impl(int line) 
    : m_stream(),
      m_line(line) {

}
