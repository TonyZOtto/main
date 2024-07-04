#include "SandboxEngine.h"

SandboxEngine::SandboxEngine(SandboxScene * pScene, QObject *parent)
    : QObject{parent}
    , mpScene(pScene)
{
    setObjectName("SandboxEngine");
    Q_CHECK_PTR(mpScene);
}

void SandboxEngine::initialize()
{

}
