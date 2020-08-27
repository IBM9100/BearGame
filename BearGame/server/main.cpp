#include <iostream>
#include <csignal>

#include "common/config/Config.h"
#include "common/service/ServiceMgr.h"
#include "common/log/Logging.h"
#include "base/Clock.h"

using namespace BearGame;
using namespace std;

static const string configPath = "./config.lua";

void OnQuitSignal(int) {
    ServiceMgr::instance().SetExitSignal();
}

void RegisterSignal() {
    signal(SIGSYS, SIG_IGN);
    signal(SIGTERM, ::OnQuitSignal);
    signal(SIGINT, ::OnQuitSignal);
}

void hhh(const char* msg, int size) {
    printf("print by printf: %s\n", msg);
}
int main() {
    RegisterSignal();
    // Logger::SetLogLevel(Logger::DEBUG);
    Logger::SetOutputFunc(hhh);
    Singleton<Config>::instance().Init(configPath);
    string user;
    Singleton<Config>::instance().GetValue("user", &user);
    cout << user << endl;
    cout << Singleton<Config>::instance().GetFps() << endl;
    ServiceMgr::instance().Init();

    while (ServiceMgr::instance().Loop()) {

    }
    
    return 0;
}