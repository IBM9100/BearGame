#include <iostream>
#include "common/config/Config.h"
#include "common/service/ServiceMgr.h"
#include "common/log/Logging.h"

using namespace BearGame;
using namespace std;

static const string configPath = "./config.lua";

int main() {

    Singleton<Config>::instance().Init(configPath);
    string user;
    Singleton<Config>::instance().GetValue("user", &user);
    cout << user << endl;
    cout << Singleton<Config>::instance().GetFps() << endl;
    ServiceMgr::instance().Init();

    LOG_TRACE << "Output Log Test";

    while (ServiceMgr::instance().Loop()) {
        LOG_TRACE << "Output Log Test";
    }
    
    return 0;
}