#include "OutputModule.h"

OutputModule::OutputModule(QObject *parent)
    : EngineModule{Output, parent}
{
    setObjectName("OutputModule");
}

void OutputModule::initialize()
{

}

Success OutputModule::isValid() const
{
    Success success;
    return success;

}

KeyMap OutputModule::defaltSettings() const
{
    return KeyMap();

}
