#pragma once

#include <QApplication>

class MainSettings;
class CommandLine;
class SandboxEngine;
class SandboxMainWindow;

#include "SandboxData.h"

class SandboxApplication : public QApplication
{
    Q_OBJECT
public: // ctors
    explicit SandboxApplication(int &argc, char **argv);

public slots:
    void initialize(void);
    void configure(void);
    void setup(void);
    void objconnect(void) {;}
    void start(void);

signals:
    void initialized(void);
    void configured(void);
    void setuped(void);
    void objconnected(void);
    void started(void);

public: // const

public: // non-const
    void set(SandboxMainWindow * pMainWindow);

public: // pointers
    SandboxMainWindow * mainWindow();
    CommandLine * commandLine();
    MainSettings * settings();

private:
    SandboxMainWindow * mpMainWindow=nullptr;
    SandboxEngine * mpEngine=nullptr;
    SandboxData mData;

};

inline void SandboxApplication::set(SandboxMainWindow *pMainWindow) { Q_CHECK_PTR(pMainWindow); mpMainWindow = pMainWindow; }
inline SandboxMainWindow *SandboxApplication::mainWindow() { Q_CHECK_PTR(mpMainWindow); return mpMainWindow; }

