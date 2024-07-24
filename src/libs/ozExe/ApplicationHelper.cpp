#include "ApplicationHelper.h"

#include <QApplication>
#include <QCoreApplication>
#include <QGuiApplication>

#include "AppSettings.h"
#include "CommandLine.h"
#include "ConsoleApplication.h"
#include "GuiApplication.h"
#include "WidgetApplication.h"

ApplicationHelper::ApplicationHelper(WidgetApplication *parent)
    : QObject(parent)
    , mpWidgetApplication(parent)
    , mpCommandLine(new CommandLine(this))
    , mpAppSettings(new AppSettings(this))
    , mType(Widget)
{
    setObjectName("ApplicationHelper:WidgetApplication");
}

ApplicationHelper::ApplicationHelper(ConsoleApplication *parent)
    : QObject(parent)
    , mpConsoleApplication(parent)
    , mpCommandLine(new CommandLine(this))
    , mpAppSettings(new AppSettings(this))
    , mType(Core)
{
    setObjectName("ApplicationHelper:ConsoleApplication");
}

ApplicationHelper::ApplicationHelper(GuiApplication *parent)
    : QObject(parent)
    , mpGuiApplication(parent)
    , mpCommandLine(new CommandLine(this))
    , mType(Gui)
{
    setObjectName("ApplicationHelper:GuiApplication");
}

QCoreApplication *ApplicationHelper::core()
{
    QCoreApplication * result=nullptr;
    if (mpConsoleApplication)
        result = mpConsoleApplication;
    else if (mpGuiApplication)
        result = mpGuiApplication;
    else if (mpWidgetApplication)
        result = mpWidgetApplication;
    return result;
}

ConsoleApplication *ApplicationHelper::consoleApp()
{
    ConsoleApplication * result = nullptr;
    if (nullptr != mpConsoleApplication)
        result = mpConsoleApplication;
    Q_CHECK_PTR(result);
    return result;
}

GuiApplication *ApplicationHelper::guiApp()
{
    GuiApplication * result = nullptr;
    if (nullptr != mpGuiApplication)
        result = mpGuiApplication;
    Q_CHECK_PTR(result);
    return result;
}

WidgetApplication *ApplicationHelper::widgetApp()
{
    WidgetApplication * result = nullptr;
    if (nullptr != mpWidgetApplication)
        result = mpWidgetApplication;
    Q_CHECK_PTR(result);
    return result;
}

