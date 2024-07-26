#include "FaceDetectionModule.h"

FaceDetectionModule::FaceDetectionModule(QObject *parent)
    : EngineModule{FaceDetection, parent}
{
    setObjectName("FaceDetectionModule");
}

void FaceDetectionModule::initialize()
{

}

Success FaceDetectionModule::isValid() const
{
    Success success;
    return success;

}

KeyMap FaceDetectionModule::defaltSettings() const
{
    return KeyMap();

}
