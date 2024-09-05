#pragma once
#include "ozExe.h"

#include <QObject>
class QCoreApplication;
class QFileInfo;

#include <VersionInfo.h>
class BaseMainWindow;
class CommandLine;
class ConsoleApplication;
class GuiApplication;
class Settings;
class TriggerManager;
class WidgetApplication;

/* Usage:
 *  In .cpp source
 *      * Outside any function:
 *          Q_GLOBAL_STATIC(ApplicationHelper, APPH)
 *      * In initialization function (maybe main.cpp):
 *          APPH->set(&applicationInstance);
 *          APPH->set(VersionInfoInstance);
 *          APPH->set(MainWindowInstance);
 *          APPH->makeConnections(MainWindowInstance);
 */

class OZEXE_EXPORT ApplicationHelper : public QObject
{
    Q_OBJECT
public: // types
    enum Type { $null = 0, Console, Gui, Widget, $max };
    Q_ENUM(Type)

public: // ctors
    explicit ApplicationHelper();

public slots:
    void initialize();
    void configure();
    void setup();
    void windowInitialized();
    void handleStartupError(const QString errorString);

signals:
    void initialized();
    void configured();
    void setuped();
    void startupError(const QString errorString);
    void startupComplete();

public: // const
    Type type() const;
    VersionInfo versionInfo() const;

public: // non-const
    void set(WidgetApplication *wapp);
    void set(ConsoleApplication *capp);
    void set(GuiApplication *gapp);
    void set(BaseMainWindow *mainw);
    void set(const VersionInfo vi);
    void makeConnections();
    void forkTroll(const QFileInfo &logFI);
    void hookTroll(void * handlerFunction);
    void unforkTroll();

public: // pointers
    QCoreApplication * core();
    ConsoleApplication * consoleApp();
    GuiApplication * guiApp();
    WidgetApplication * widgetApp();
    BaseMainWindow * mainWindow();
    CommandLine * commandLine();
    Settings * settings();
    TriggerManager * triggerManager();

private:
    ConsoleApplication * mpConsoleApplication=nullptr;
    GuiApplication * mpGuiApplication=nullptr;
    WidgetApplication * mpWidgetApplication=nullptr;
    CommandLine * mpCommandLine=nullptr;
    Settings * mpSettings=nullptr;
    BaseMainWindow * mpMainWindow=nullptr;
    TriggerManager * mpTriggerManager=nullptr;
    VersionInfo mVersionInfo;
    Type mType=$null;
};

inline ApplicationHelper::Type ApplicationHelper::type() const { return mType; }
inline VersionInfo ApplicationHelper::versionInfo() const { return mVersionInfo; }
inline BaseMainWindow *ApplicationHelper::mainWindow() { Q_ASSERT(mpMainWindow);  return mpMainWindow; }
inline CommandLine *ApplicationHelper::commandLine() { Q_ASSERT(mpCommandLine);  return mpCommandLine; }
inline Settings *ApplicationHelper::settings() { Q_ASSERT(mpSettings);  return mpSettings; }
inline TriggerManager *ApplicationHelper::triggerManager() { Q_CHECK_PTR(mpTriggerManager);  return mpTriggerManager; }


