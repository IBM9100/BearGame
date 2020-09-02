#include "service/ServiceMgr.h"
#include "common/config/Config.h"
#include "common/log/Logging.h"
#include "base/Sleep.h"
#include "base/Clock.h"

using namespace BearGame;


bool ServiceMgr::Init() {
    uint32_t fps = Singleton<Config>::instance().GetFps();
    assert(fps != 0);
    
    // 30帧 为 33ms
    m_frameTime = 1000 / fps;
    
    _InitService();

    return true;
}

void ServiceMgr::SetExitSignal() {
    m_exitFlag = true;
}

bool ServiceMgr::Loop() {
    bool result = false;
    Clock::instance().Update();
    int64_t start = Clock::instance().Tick();

    if (m_exitFlag) {
        LOG_TRACE << "exiting...";
        goto Exit0;
    }

    for (auto& service : m_runningService) {
        service->Loop();
    }

    result = true;
Exit0:
    // MsSleep(34);
    Clock::instance().Update();
    int64_t end = Clock::instance().Tick();
    assert(end >= start);

    uint32_t cost = end - start;

    if (cost > m_frameTime) {
        LOG_TRACE << "超出时间了";
    } else {
        uint32_t sleepTime = m_frameTime - cost;
        // LOG_TRACE << "sleepTime: " << sleepTime;
        MsSleep(sleepTime);
    }
    

    return result;
}

bool ServiceMgr::_InitService() {
    bool result = false;
    // move ctor
    std::unique_ptr<Service> service(Service::CreateService());
    service->Init("name");
    m_runningService.push_back(std::move(service));

    result = true;

Exit0:
    return result;
}

// bool ServiceMgr::AddService(ServiceType serviceType, const std::string& serviceName) {

// }