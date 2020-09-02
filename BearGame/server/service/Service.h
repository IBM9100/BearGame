#ifndef BEARGAME_SERVER_COMMON_SERVICE_SERVICE_H
#define BEARGAME_SERVER_COMMON_SERVICE_SERVICE_H

#include <string>

#include "base/Noncopyable.h"

namespace BearGame {

enum ServiceType {
    SERVICE_TYPE_NULL = 0,
    SERVICE_TYPE_SCRIPT = 1,
};

class Service : private Noncopyable {
public:
    Service() = default;
    virtual ~Service() = default;
public:
    virtual bool Init(const std::string& serviceName) = 0;
    virtual void UnInit() = 0;
    virtual void Update() = 0;

    static Service* CreateService();
public:
    void Loop() { Update(); }
};

}


#endif