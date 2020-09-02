#ifndef BEARGAME_SERVER_COMMON_SERVICE_SERVICEMGR_H
#define BEARGAME_SERVER_COMMON_SERVICE_SERVICEMGR_H

#include <cstdint>
#include <vector>
#include <memory>

#include "service/Service.h"
#include "base/Singleton.h"

namespace BearGame {


class ServiceMgr : public Singleton<ServiceMgr> {
public:
    bool Init();
    bool UnInit();
    bool Loop();
    void SetExitSignal();
public:
    bool AddService(ServiceType serviceType, const std::string& serviceName);
    bool DelService();
private:
    bool _InitService();
private:
    std::vector<std::unique_ptr<Service>> m_runningService;
    uint32_t m_frameTime;
    bool m_exitFlag;
};


}

#endif