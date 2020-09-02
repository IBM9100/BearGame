#include <iostream>
#include <csignal>

#include "common/config/Config.h"
#include "service/ServiceMgr.h"
#include "common/log/Logging.h"
#include "base/Clock.h"
#include "common/log/LogFile.h"

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

unique_ptr<LogFile> g_logFile;

void outputFunc(const char* msg, int size) {
    fwrite(msg, 1, size, stdout);
    // g_logFile->Append(msg, size);
}

void flushFunc() {
    fflush(stdout);
    // g_logFile->Flush();
}

int main() {
    RegisterSignal();
    // g_logFile.reset(new LogFile("gamesvr"));

    Logger::SetLogLevel(Logger::TRACE);
    Logger::SetOutputFunc(outputFunc);
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