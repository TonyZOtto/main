#pragma once

#include <WidgetApplication.h>

class ApplicationHelper;
class AppSettings;
class CommandLine;

#include "SandboxData.h"
class SandboxEngine;
class SandboxMainWindow;
class SandboxScene;


class SandboxApplication : public WidgetApplication
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

    void actQuit(const bool checked);


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
inline void SandboxApplication::set(SandboxMainWindow *pMainWindow) { Q_ASSERT(pMainWindow); mpMainWindow = pMainWindow; }
inline SandboxMainWindow *SandboxApplication::mainWindow() { Q_ASSERT(mpMainWindow); return mpMainWindow; }
inline SandboxEngine *SandboxApplication::engine() { Q_ASSERT(mpEngine); return mpEngine; }
inline ApplicationHelper *SandboxApplication::appHelper() { Q_ASSERT(mpHelper); return mpHelper; }

