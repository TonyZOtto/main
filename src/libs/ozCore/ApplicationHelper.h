#pragma once
#include "ozCore.h"

#include <QObject>
class QCoreApplication;
class QFileInfo;

#include <VersionInfo.h>
class BaseMainWindow;
class CommandLine;
class ConsoleApplication;
class GuiApplication;
class Settings;
class StackedMainWindow;
class TriggerManager;
class WidgetApplication;

/* Usage:
 *  In .cpp source
 *      * Outside any function:
 *          Q_GLOBAL_STATIC(ApplicationHelper, APPH)
 *      * In initialization function (maybe main.cpp):
 *          APPH->set(&applicationInstance);
 *          APPH->set(VersionInfoInstance);
 *          APPH->set(&MainWindowInstance);
 */

#define APPH ApplicationHelper::instance()

class OZCORE_EXPORT ApplicationHelper : public QObject
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
    void set(StackedMainWindow *smainw);
    void set(const VersionInfo vi);
    void makeConnections();
    void forkTroll(const QFileInfo &logFI);
    void hookTroll(void * handlerFunction);
    void unforkTroll();

public: // pointers
    static ApplicationHelper * instance();
    QCoreApplication * core();
    ConsoleApplication * consoleApp();
    GuiApplication * guiApp();
    WidgetApplication * widgetApp();
    BaseMainWindow * baseMainWindow();
    StackedMainWindow * stackedMainWindow();
    CommandLine * commandLine();
    Settings * settings();
    TriggerManager * triggerManager();

private:
    ConsoleApplication * mpConsoleApplication=nullptr;
    GuiApplication * mpGuiApplication=nullptr;
    WidgetApplication * mpWidgetApplication=nullptr;
    CommandLine * mpCommandLine=nullptr;
    Settings * mpSettings=nullptr;
    BaseMainWindow * mpBaseMainWindow=nullptr;
    StackedMainWindow * mpStackedMainWindow=nullptr;
    TriggerManager * mpTriggerManager=nullptr;
    VersionInfo mVersionInfo;
    Type mType=$null;
    static ApplicationHelper * smpInstance;
};

inline ApplicationHelper::Type ApplicationHelper::type() const { return mType; }
inline VersionInfo ApplicationHelper::versionInfo() const { return mVersionInfo; }
inline BaseMainWindow *ApplicationHelper::baseMainWindow() { Q_ASSERT(mpBaseMainWindow);  return mpBaseMainWindow; }
inline CommandLine *ApplicationHelper::commandLine() { Q_ASSERT(mpCommandLine);  return mpCommandLine; }
inline Settings *ApplicationHelper::settings() { Q_ASSERT(mpSettings);  return mpSettings; }
inline TriggerManager *ApplicationHelper::triggerManager() { Q_CHECK_PTR(mpTriggerManager);  return mpTriggerManager; }


