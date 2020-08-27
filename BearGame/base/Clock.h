#ifndef BEARGAME_BASE_CLOCK_H
#define BEARGAME_BASE_CLOCK_H

#include <cstdint>
#include <sys/time.h>

#include "base/Singleton.h"

namespace BearGame {

class Clock : public Singleton<Clock> {
public:
    void Update();
    uint64_t Now();
    struct timeval NowTv();
public:
    uint64_t Tick() { return m_tick; }
private:
    uint64_t m_tick;
};


}
#endif