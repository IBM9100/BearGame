#ifndef BEARGAME_SERVER_COMMON_SERVICE_SERVICEMGR_H
#define BEARGAME_SERVER_COMMON_SERVICE_SERVICEMGR_H

#include <cstdint>
#include "base/Singleton.h"

namespace BearGame {


class ServiceMgr : public Singleton<ServiceMgr> {
public:
    bool Init();
    bool Loop();
    bool UnInit();
    void SetExitSignal();
private:
    uint32_t m_frameTime;
    bool m_exitFlag;
};


}

#endif