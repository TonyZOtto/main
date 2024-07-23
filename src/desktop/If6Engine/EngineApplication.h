#pragma once

#include <QApplication>

#include <VersionInfo.h>

class EngineMainWindow;

class EngineApplication : public QApplication
{
    Q_OBJECT
public: // ctors
    EngineApplication(int &argc, char **argv);

public slots:
    void initialize();
    void actQuit();
    void showMainWindow();

signals:
    void initialized();

public: // const

public: // non-const

public: // pointers
    EngineMainWindow * mainWindow();

private:
    EngineMainWindow * mpMainWindow=nullptr;
};

inline EngineMainWindow *EngineApplication::mainWindow()  { Q_CHECK_PTR(mpMainWindow); return mpMainWindow; }
