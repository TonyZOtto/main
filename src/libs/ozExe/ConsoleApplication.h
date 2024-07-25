#pragma once

#include <QCoreApplication>
#include <QObject>

class ConsoleApplication : public QCoreApplication
{
    Q_OBJECT
public:
    ConsoleApplication(int &argc, char **argv);
};
