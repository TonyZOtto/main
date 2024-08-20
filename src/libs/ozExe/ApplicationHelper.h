#pragma once
#include "ozExe.h"

#include <QObject>
class QCoreApplication;

#include <VersionInfo.h>
class AppSettings;
class CommandLine;
class TriggerManager;
class ConsoleApplication;
class GuiApplication;
class WidgetApplication;

/* Usage:
 *  In .cpp source
 *      * Outside any function:
 *          Q_GLOBAL_STATIC(ApplicationHelper, APPH)
 *      * In initialization function (maybe main.cpp):
 *          APPH->set(&applicationInstance);
 *          APPH->set(VersionInfoInstance);
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

signals:

public: // const
    Type type() const;
    VersionInfo versionInfo() const;

public: // non-const
    void set(WidgetApplication *wapp);
    void set(ConsoleApplication *capp);
    void set(GuiApplication *gapp);
    void set(const VersionInfo vi);

public: // pointers
    QCoreApplication * core();
    /*
    ConsoleApplication * consoleApp();
    GuiApplication * guiApp();
    WidgetApplication * widgetApp();
    */
    CommandLine * commandLine();
    AppSettings * appSettings();
    TriggerManager * triggerManager();

private:
    ConsoleApplication * mpConsoleApplication=nullptr;
    GuiApplication * mpGuiApplication=nullptr;
    WidgetApplication * mpWidgetApplication=nullptr;
    CommandLine * mpCommandLine=nullptr;
    AppSettings * mpAppSettings=nullptr;
    TriggerManager * mpTriggerManager=nullptr;
    VersionInfo mVersionInfo;
    Type mType=$null;
};

inline ApplicationHelper::Type ApplicationHelper::type() const { return mType; }
inline VersionInfo ApplicationHelper::versionInfo() const { return mVersionInfo; }
inline CommandLine *ApplicationHelper::commandLine() { Q_CHECK_PTR(mpCommandLine);  return mpCommandLine; }
inline AppSettings *ApplicationHelper::appSettings() { Q_CHECK_PTR(mpAppSettings);  return mpAppSettings; }
inline TriggerManager *ApplicationHelper::triggerManager() { Q_CHECK_PTR(mpTriggerManager);  return mpTriggerManager; }


