#include "ErrorManager.h"

#include <QCoreApplication>

ErrorManager::ErrorManager()
    : QObject{QCoreApplication::instance()}
{
    setObjectName("ErrorManager");
}
