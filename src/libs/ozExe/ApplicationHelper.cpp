#include "ApplicationHelper.h"

#include <QApplication>
#include <QCoreApplication>
#include <QGuiApplication>

#include "CommandLine.h"

ApplicationHelper::ApplicationHelper(WidgetApplication *parent)
    : mpWidgetApplication(parent)
    , mType(App)
{
    setObjectName("ApplicationHelper:WidgetApplication");
}

ApplicationHelper::ApplicationHelper(ConsoleApplication *parent)
    : mpConsoleApplication(parent)
    , mType(Core)
{
    setObjectName("ApplicationHelper:ConsoleApplication");

}

ApplicationHelper::ApplicationHelper(GuiApplication *parent)
    : mpGuiApplication(parent)
    , mType(Gui)
{
    setObjectName("ApplicationHelper:GuiApplication");

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

