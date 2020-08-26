#include <iostream>
#include "common/config/Config.h"
#include "common/service/ServiceMgr.h"
#include "base/Singleton.h"


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
    
    while (ServiceMgr::instance().Loop()) {}
    
    return 0;
}