#pragma once
#include "ozExe.h"

#include <QApplication>
#include <QObject>

#include <ApplicationHelper.h>

class OZEXE_EXPORT WidgetApplication : public QApplication
{
    Q_OBJECT
public: // ctors
    WidgetApplication(int &argc, char **argv);

public:


private:
};


