#pragma once

#include <WidgetApplication.h>

class QVariant;

#include <VersionInfo.h>
class ApplicationHelper;
class Key;

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
    void configure();
    void actQuit();
    void showMainWindow();
    void watchedSetting(const Key &aKey,
                        const QVariant &aNewValue,
                        const QVariant &aOldValue);

signals:
    void initialized();
    void urlChanged(const QUrl &newUrl);

public: // const

public: // non-const

public: // pointers
    ApplicationHelper * helper();
    EngineSettings * settings();
    EngineModule * module(const EngineModule::Module mix);
    EngineMainWindow * mainWindow();

public slots:

private:
    ApplicationHelper * mpHelper=nullptr;
    EngineSettings * mpSettings=nullptr;
    EngineMainWindow * mpMainWindow=nullptr;
    EngineModule::List mModuleList;
};

inline ApplicationHelper *EngineApplication::helper()  { Q_ASSERT(mpHelper); return mpHelper; }
inline EngineSettings *EngineApplication::settings() { Q_ASSERT(mpSettings); return mpSettings; }
inline EngineMainWindow *EngineApplication::mainWindow() { Q_ASSERT(mpMainWindow); return mpMainWindow; }

