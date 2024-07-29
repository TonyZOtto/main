#pragma once

#include <WidgetApplication.h>

#include <VersionInfo.h>
class ApplicationHelper;

#include "EngineModule.h"
class EngineMainWindow;
class EngineSettings;

class FaceDetModule;
class InputModule;
class MarkerModule;
class OutputModule;

class EngineApplication : public WidgetApplication
{
    Q_OBJECT
public: // types

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
    ApplicationHelper * helper();
    EngineSettings * settings();
    EngineModule * module(const EngineModule::Module mix);
    EngineMainWindow * mainWindow();

private:
    ApplicationHelper * mpHelper=nullptr;
    EngineSettings * mpSettings=nullptr;
    EngineMainWindow * mpMainWindow=nullptr;
    EngineModule::List mModuleList;
};

inline ApplicationHelper *EngineApplication::helper()  { Q_ASSERT(mpHelper); return mpHelper; }
inline EngineSettings *EngineApplication::settings() { Q_ASSERT(mpSettings); return mpSettings; }
inline EngineMainWindow *EngineApplication::mainWindow() { Q_ASSERT(mpMainWindow); return mpMainWindow; }

