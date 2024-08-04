#include "LogEngine.h"

#include <QCoreApplication>

LogEngine::LogEngine()
    : QObject{qApp}
{
    setObjectName("LogEngine");
}

LogEngine::~LogEngine()
{
    ;
}
