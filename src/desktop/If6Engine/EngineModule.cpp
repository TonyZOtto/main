#include "EngineModule.h"

#include <ObjectHelper.h>

#include "EngineApplication.h"

EngineModule::EngineModule(const Module aModule, EngineApplication *parent)
    : QObject{parent}
    , mpApplication(parent)
    , mModule(aModule)
{
    setObjectName("BaseEngineModule:" + moduleName());
}

void EngineModule::initialize()
{
    initializeSettings();
}

void EngineModule::connections()
{

}

void EngineModule::configure()
{

}

void EngineModule::setup()
{

}

QString EngineModule::moduleName() const
{
    ObjectHelper tOH(this);
    return tOH.enumKey("Module", module()) + "Module";
}

Success EngineModule::isValid() const
{
    Success success;
    success.expect($nullModule != module());
    success.expect($maxModule > module());
    return success;
}

EngineSettings *EngineModule::settings()
{
    return application()->settings();
}

KeyMap EngineModule::defaltSettings() const
{
    return KeyMap();
}

void EngineModule::initializeSettings()
{

}

