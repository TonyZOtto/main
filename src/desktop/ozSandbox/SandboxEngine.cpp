#include "SandboxEngine.h"

#include "SandboxApplication.h"
#include "SandboxScene.h"

SandboxEngine::SandboxEngine(SandboxApplication *parent)
    : QObject(parent)
    , mpApplication(parent)
{
    setObjectName("SandboxEngine");
}

void SandboxEngine::initialize()
{

}

void SandboxEngine::setSubjectPhoto(const ColorPhoto &aCP)
{
    mSubjectPhoto.set(aCP);
    scene()->set(SandboxScene::BackImage, mSubjectPhoto);
}

SandboxScene *SandboxEngine::scene()
{
    return app()->scene();
}

QObject *SandboxEngine::object()
{
    return parent();
}
