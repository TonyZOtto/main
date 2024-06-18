#pragma once
#include "ozCore.h"

#include <QObject>
#include "BaseApplication.h"

class OZCORE_EXPORT WidgetApplication : public BaseApplication
{
    Q_OBJECT
protected: // ctors
    WidgetApplication(int argc, char *argv[]);


protected: // non-const
    void initialize();
    void configure();
    void start();
    void finish();
};
