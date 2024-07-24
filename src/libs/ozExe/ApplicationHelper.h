#pragma once
#include "ozExe.h"

#include <QObject>
class QCoreApplication;

#include <VersionInfo.h>
class AppSettings;
class CommandLine;
class ConsoleApplication;
class GuiApplication;
class WidgetApplication;

class OZEXE_EXPORT ApplicationHelper : public QObject
{
    Q_OBJECT
public:
    enum Type { $null = 0, Core, Gui, Widget, $max };
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
    QCoreApplication * core();
    ConsoleApplication * consoleApp();
    GuiApplication * guiApp();
    WidgetApplication * widgetApp();
    CommandLine * commandLine();
    AppSettings * appSettings();

private:
    ConsoleApplication * mpConsoleApplication=nullptr;
    GuiApplication * mpGuiApplication=nullptr;
    WidgetApplication * mpWidgetApplication=nullptr;
    CommandLine * mpCommandLine=nullptr;
    AppSettings * mpAppSettings=nullptr;
    VersionInfo mVersionInfo;
    Type mType=$null;
};

inline ApplicationHelper::Type ApplicationHelper::type() const { return mType; }
inline CommandLine *ApplicationHelper::commandLine() { Q_CHECK_PTR(mpCommandLine);  return mpCommandLine; }
inline AppSettings *ApplicationHelper::appSettings() { Q_CHECK_PTR(mpAppSettings);  return mpAppSettings; }


