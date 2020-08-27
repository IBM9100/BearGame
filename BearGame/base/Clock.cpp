#include <time.h>

#include "base/Clock.h"

using namespace BearGame;

void Clock::Update() {
    struct timespec sp;
    clock_gettime(CLOCK_MONOTONIC_RAW, &sp);
    m_tick = sp.tv_sec * 1000 + (sp.tv_nsec % 1000000) / 1000000;
}

struct timeval Clock::NowTv() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv;
}

uint64_t Clock::Now() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000 + tv.tv_usec);
}