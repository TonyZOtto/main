#pragma once
#include "ozExe.h"

#include <QApplication>
#include <QObject>

class ApplicationHelper;

class OZEXE_EXPORT WidgetApplication : public QApplication
{
    Q_OBJECT
public:
    WidgetApplication(int &argc, char **argv);

private:
    ApplicationHelper * mpHelper=nullptr;
};
