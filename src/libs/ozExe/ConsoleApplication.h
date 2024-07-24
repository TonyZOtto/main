#pragma once

#include <QCoreApplication>
#include <QObject>

class ApplicationHelper;

class ConsoleApplication : public QCoreApplication
{
    Q_OBJECT
public:
    ConsoleApplication(int &argc, char **argv);

private:
    ApplicationHelper * mpHelper=nullptr;
};
