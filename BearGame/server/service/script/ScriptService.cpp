#include "service/script/ScriptService.h"

using namespace BearGame;

ScriptService::ScriptService()
    : m_scriptMgr() {
}

bool ScriptService::Init(const std::string& serviceName) {
    m_scriptMgr.Init();
    return true;
}

void ScriptService::UnInit() {

}

void ScriptService::Update() {
    m_scriptMgr.Update();
}