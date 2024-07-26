#include "EngineModule.h"

#include <ObjectHelper.h>

EngineModule::EngineModule(const Module aModule, QObject *parent)
    : QObject{parent}
    , mModule(aModule)
{
    ObjectHelper tOH(this);
    setObjectName("BaseEngineModule:" + tOH.enumKey("Module", aModule));
}

void EngineModule::initialize()
{

}

Success EngineModule::isValid() const
{
    Success success;
    success.expect($nullModule != module());
    success.expect($maxModule > module());
    return success;
}

KeyMap EngineModule::defaltSettings() const
{
    return KeyMap();
}

void EngineModule::initializeSettings()
{

}

