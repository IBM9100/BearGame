#include <time.h>

#include "base/Clock.h"

using namespace BearGame;

void Clock::Update() {
    struct timespec sp;
    clock_gettime(CLOCK_MONOTONIC_RAW, &sp);
    m_tick = sp.tv_sec * 1000 + sp.tv_nsec / 1000000;
}