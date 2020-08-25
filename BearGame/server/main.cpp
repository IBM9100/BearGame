#include <iostream>
#include "BearGame/server/common/Config.h"
#include "BearGame/base/Singleton.h"


using namespace BearGame;
using namespace std;

static const string configPath = "./config.lua";

int main() {

    Singleton<Config>::Instance().Init(configPath);
    string user;
    Singleton<Config>::Instance().GetValue("user", &user);
    cout << user << endl;
    cout << Singleton<Config>::Instance().GetFps() << endl;
    return 0;
}