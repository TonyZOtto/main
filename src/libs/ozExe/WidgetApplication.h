#pragma once
#include "ozExe.h"

#include <QObject>
#include "BaseApplication.h"

class OZEXE_EXPORT WidgetApplication : public BaseApplication
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
