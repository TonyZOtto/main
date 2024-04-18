#pragma once

#include <ConsoleApplication>

#include <QStringList>

class StatusConsoleApplication : public ConsoleApplication
{
    Q_OBJECT
public:
    StatusConsoleApplication(int argc, char *argv[]);

public slots:
    virtual void initialize();
    virtual void configure();
    virtual void start();
    virtual void finish();

private slots:
    void exeInfo();
    void qtInfo();
    void libInfo();
    void pathInfo();

private:
    QStringList mLibraryNames;
};
