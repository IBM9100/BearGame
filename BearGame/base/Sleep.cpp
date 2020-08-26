#include "base/Sleep.h"

#include <sys/select.h>

namespace BearGame {

void MsSleep(unsigned int ms) {
    struct timeval tv;
    tv.tv_sec = ms / 1000;
    tv.tv_usec = (ms % 1000) * 1000;
    select(0, nullptr, nullptr, nullptr, &tv);
}
}