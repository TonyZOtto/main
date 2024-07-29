#pragma once
#include "ozExe.h"

#include <QCoreApplication>
#include <QObject>

class ApplicationHelper;

class OZEXE_EXPORT ConsoleApplication : public QCoreApplication
{
    Q_OBJECT
public:
    ConsoleApplication(int &argc, char **argv);

private:
    ApplicationHelper * mpHelper=nullptr;
};
