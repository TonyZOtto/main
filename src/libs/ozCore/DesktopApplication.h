#pragma once
#include "../ozCore.h"

#include <QObject>
#include "BaseApplication.h"

class OZCORE_EXPORT DesktopApplication : public BaseApplication
{
    Q_OBJECT
protected: // ctors
    DesktopApplication(int argc, char *argv[]);


protected: // non-const
    void initialize();
    void configure();
    void start();
    void finish();

};
