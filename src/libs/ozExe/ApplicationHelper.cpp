#include "ApplicationHelper.h"

#include <QApplication>
#include <QCoreApplication>
#include <QGuiApplication>

#include "AppSettings.h"
#include "CommandLine.h"
#include "TriggerManager.h"
#include "ConsoleApplication.h"
#include "GuiApplication.h"
#include "WidgetApplication.h"

ApplicationHelper::ApplicationHelper()
    : QObject(qApp)
    , mpCommandLine(new CommandLine(this))
    , mpAppSettings(new AppSettings(this))
    , mpTriggerManager(new TriggerManager(this))
    , mType($null)
{
    setObjectName("ApplicationHelper:"
                  + QCoreApplication::applicationName());
}

void ApplicationHelper::set(WidgetApplication *wapp)
{
    Q_ASSERT(qobject_cast<WidgetApplication *>(wapp));
    mpWidgetApplication = wapp;
    mType = Widget;
}

void ApplicationHelper::set(ConsoleApplication *capp)
{
    Q_ASSERT(qobject_cast<ConsoleApplication *>(capp));
    mpConsoleApplication = capp;
    mType = Console;
}

void ApplicationHelper::set(GuiApplication *gapp)
{
    Q_ASSERT(qobject_cast<GuiApplication *>(gapp));
    mpGuiApplication = gapp;
    mType = Gui;
}

void ApplicationHelper::set(const VersionInfo vi)
{
    mVersionInfo = vi;
    vi.updateApp(core());
}

QCoreApplication *ApplicationHelper::core()
{
    QCoreApplication * result=nullptr;
    switch (type())
    {
    case Console:   result = mpConsoleApplication;  break;
    case Gui:       result = mpGuiApplication;      break;
    case Widget:    result = mpWidgetApplication;   break;
    default:        /* leave nullptr */             break;
    }
    return result;
}




