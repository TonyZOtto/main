#include "QQObject.h"

QQObject::QQObject(QObject *parent) : QObject{parent}
{
    setObjectName("QQObject");
}
