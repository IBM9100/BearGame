#ifndef BEARGAME_SERVER_SERVICE_SCRIPTSERVICE_H
#define BEARGAME_SERVER_SERVICE_SCRIPTSERVICE_H

#include "service/Service.h"
#include "service/script/ScriptMgr.h"

namespace BearGame {

class ScriptService : public Service {
public:
    ScriptService();
    ~ScriptService() = default;
public:
    bool Init(const std::string& serviceName) override;
    void UnInit() override;
    void Update() override;
private:
    ScriptMgr m_scriptMgr;

};


}

#endif