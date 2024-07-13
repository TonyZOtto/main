#pragma once

#include <QApplication>

class ApplicationHelper;
class AppSettings;
class CommandLine;

#include "SandboxData.h"
class SandboxEngine;
class SandboxMainWindow;
class SandboxScene;


class SandboxApplication : public QApplication
{
    Q_OBJECT
public: // ctors
    explicit SandboxApplication(int &argc, char **argv);

public slots:
    void initialize(void);
    void objconnect(void);
    void configure(void);
    void setup(void);
    void start(void);

signals:
    void initialized(void);
    void objconnected(void);
    void configured(void);
    void setuped(void);
    void started(void);

public: // const
    SandboxData data() const;

public: // non-const
    void set(SandboxMainWindow * pMainWindow);

public: // pointers
    SandboxMainWindow * mainWindow();
    SandboxEngine * engine();
    ApplicationHelper * appHelper();
    SandboxScene * scene();
    CommandLine * commandLine();
    AppSettings * settings();

private:
    SandboxMainWindow * mpMainWindow=nullptr;
    SandboxEngine * mpEngine=nullptr;
    ApplicationHelper * mpHelper=nullptr;
    SandboxData mData;

};

inline SandboxData SandboxApplication::data() const { return mData; }
inline void SandboxApplication::set(SandboxMainWindow *pMainWindow) { Q_CHECK_PTR(pMainWindow); mpMainWindow = pMainWindow; }
inline SandboxMainWindow *SandboxApplication::mainWindow() { Q_CHECK_PTR(mpMainWindow); return mpMainWindow; }
inline SandboxEngine *SandboxApplication::engine() { Q_CHECK_PTR(mpEngine); return mpEngine; }
inline ApplicationHelper *SandboxApplication::appHelper() { Q_CHECK_PTR(mpHelper); return mpHelper; }

