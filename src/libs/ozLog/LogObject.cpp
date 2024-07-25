#include "LogObject.h"

Log::Log(QObject *parent)
    : QObject{parent}
{
    setObjectName("Log");
}

