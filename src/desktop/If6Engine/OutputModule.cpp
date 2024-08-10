#include "OutputModule.h"

OutputModule::OutputModule(EngineApplication *parent)
    : EngineModule{Output, parent}
{
    setObjectName("OutputModule");
}

void OutputModule::initialize()
{

}

Success OutputModule::isValid() const
{
    Success success = EngineModule::isValid();
    success.expect(Output == module());
    success.expect("OutputModule" == moduleName());
    success.expect("OutputModule" == objectName());
    return success;
}

KeyMap OutputModule::defaltSettings() const
{
    return KeyMap();

}
