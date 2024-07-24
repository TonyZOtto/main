#pragma once
#include "ozExe.h"

#include <QObject>
class CommandLine;
class AppSettings;

#include <VersionInfo.h>
class WidgetApplication;
class ConsoleApplication;
class GuiApplication;

class OZEXE_EXPORT ApplicationHelper : public QObject
{
    Q_OBJECT
public:
    enum Type { $null = 0, App, Core, Gui, $max };
    Q_ENUM(Type)

public:
    explicit ApplicationHelper(WidgetApplication *parent);
    explicit ApplicationHelper(ConsoleApplication *parent);
    explicit ApplicationHelper(GuiApplication *parent);

public slots:

signals:

public: // const
    Type type() const;

public: // non-const
    void set(const VersionInfo vi);

public: // pointers
    ConsoleApplication * consoleApp();
    GuiApplication * guiApp();
    WidgetApplication * widgetApp();
    CommandLine * commandLine();
    AppSettings * appSettings();

private:
    WidgetApplication * mpWidgetApplication=nullptr;
    ConsoleApplication * mpConsoleApplication=nullptr;
    GuiApplication * mpGuiApplication=nullptr;
    CommandLine * mpCommandLine=nullptr;
    AppSettings * mpAppSettings=nullptr;
    VersionInfo mVersionInfo;
    Type mType=$null;
};

inline ApplicationHelper::Type ApplicationHelper::type() const { return mType; }
inline CommandLine *ApplicationHelper::commandLine() { Q_CHECK_PTR(mpCommandLine);  return mpCommandLine; }
inline AppSettings *ApplicationHelper::appSettings() { Q_CHECK_PTR(mpAppSettings);  return mpAppSettings; }


