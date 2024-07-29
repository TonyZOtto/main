#include "FaceDetModule.h"

FaceDetModule::FaceDetModule(EngineApplication *parent)
    : EngineModule{FaceDet, parent}
{
    setObjectName("FaceDetModule");
}

void FaceDetModule::initialize()
{

}

Success FaceDetModule::isValid() const
{
    Success success;
    return success;

}

KeyMap FaceDetModule::defaltSettings() const
{
    return KeyMap();

}
