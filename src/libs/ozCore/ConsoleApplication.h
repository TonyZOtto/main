#pragma once
#include "ozCore.h"

#include <QCoreApplication>
#include <QObject>

class ApplicationHelper;

class OZCORE_EXPORT ConsoleApplication : public QCoreApplication
{
    Q_OBJECT
public:
    ConsoleApplication(int &argc, char **argv);

private:
};
