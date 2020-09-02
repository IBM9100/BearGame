#include "service/Service.h"
#include "service/script/ScriptService.h"

using namespace BearGame;

Service* Service::CreateService() {
    return new ScriptService();
}