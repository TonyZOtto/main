#include "ApplicationHelper.h"

#include <QtDebug>
#include <QApplication>
#include <QCoreApplication>
#include <QFileInfo>
#include <QGuiApplication>

#include "BaseMainWindow.h"
#include "CommandLine.h"
#include "ConsoleApplication.h"
#include "GuiApplication.h"
#include "Settings.h"
#include "SettingsName.h"
#include "StackedMainWindow.h"
#include "TriggerManager.h"
#include "WidgetApplication.h"

ApplicationHelper * ApplicationHelper::smpInstance = nullptr;


ApplicationHelper::ApplicationHelper()
    : QObject(qApp)
    , mpCommandLine(new CommandLine(this))
    , mpTriggerManager(new TriggerManager(this))
    , mType($null)
{
    setObjectName("ApplicationHelper%" + QCoreApplication::organizationName()
                  + ":" + QCoreApplication::applicationName());
    qInfo() << Q_FUNC_INFO << this;
}

void ApplicationHelper::initialize()
{
    qInfo() << Q_FUNC_INFO;
    commandLine()->process();
    mpSettings = new Settings(commandLine()->settingsName(), this);
    emit initialized();
}

void ApplicationHelper::configure()
{
    qInfo() << Q_FUNC_INFO;

    emit configured();
}

void ApplicationHelper::setup()
{
    qInfo() << Q_FUNC_INFO;

    emit setuped();
}

void ApplicationHelper::handleStartupError(const QString errorString)
{
    const QString cFrom = sender() ? sender()->objectName() : "Unknown Sender";
    qFatal() << "Initialization Error from"
             << cFrom << ":" << errorString;
}

void ApplicationHelper::set(WidgetApplication *wapp)
{
    Q_ASSERT(qobject_cast<WidgetApplication *>(wapp));
    qInfo() << Q_FUNC_INFO << wapp->objectName();
    mpWidgetApplication = wapp;
    mType = Widget;
}

void ApplicationHelper::set(ConsoleApplication *capp)
{
    Q_ASSERT(qobject_cast<ConsoleApplication *>(capp));
    qInfo() << Q_FUNC_INFO << capp->objectName();
    mpConsoleApplication = capp;
    mType = Console;
}

void ApplicationHelper::set(GuiApplication *gapp)
{
    Q_ASSERT(qobject_cast<GuiApplication *>(gapp));
    qInfo() << Q_FUNC_INFO << gapp->objectName();
    mpGuiApplication = gapp;
    mType = Gui;
}

void ApplicationHelper::set(BaseMainWindow *mainw)
{
    Q_ASSERT(qobject_cast<BaseMainWindow *>(mainw));
    qInfo() << Q_FUNC_INFO << mainw->objectName();
    mpBaseMainWindow = mainw;
}

void ApplicationHelper::set(StackedMainWindow *smainw)
{
    Q_ASSERT(qobject_cast<StackedMainWindow *>(smainw));
    Q_ASSERT(qobject_cast<BaseMainWindow *>(smainw));
    qInfo() << Q_FUNC_INFO << smainw->objectName();
    mpStackedMainWindow = smainw;
    mpBaseMainWindow = smainw;
}

void ApplicationHelper::set(const VersionInfo vi)
{
    qInfo() << Q_FUNC_INFO << vi.toString();
    mVersionInfo = vi;
}

void ApplicationHelper::makeConnections()
{
    qInfo() << Q_FUNC_INFO << objectName();

    switch (type())
    {
    case Widget:
        connect(widgetApp(), &WidgetApplication::initialized,
                baseMainWindow(), &BaseMainWindow::initialize);
        connect(baseMainWindow(), &BaseMainWindow::initialized,
                widgetApp(), &WidgetApplication::configure);
        connect(widgetApp(), &WidgetApplication::configured,
                baseMainWindow(), &BaseMainWindow::configure);
        connect(baseMainWindow(), &BaseMainWindow::configured,
                widgetApp(), &WidgetApplication::setup);
        connect(widgetApp(), &WidgetApplication::setuped,
                baseMainWindow(), &BaseMainWindow::setup);
        connect(baseMainWindow(), &BaseMainWindow::setuped,
                widgetApp(), &WidgetApplication::startupComplete);
        connect(widgetApp(), &WidgetApplication::startupError,
                instance(), &ApplicationHelper::handleStartupError);
        connect(baseMainWindow(), &BaseMainWindow::startupError,
                instance(), &ApplicationHelper::handleStartupError);
        connect(instance(), &ApplicationHelper::startupError,
                instance(), &ApplicationHelper::handleStartupError);
        break;

    // MUSTDO Handle other App type()s

    default:
        Q_ASSERT(!"MUSTDO");
        break;
    };
}

void ApplicationHelper::forkTroll(const QFileInfo &logFI)
{
    Q_UNUSED(logFI); // MUSTDO
}

ApplicationHelper *ApplicationHelper::instance()
{
    ApplicationHelper * result = smpInstance;
    if ( ! result)
        result = smpInstance = new ApplicationHelper();
    return result;
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

WidgetApplication *ApplicationHelper::widgetApp()
{
    Q_ASSERT(Widget == type());
    Q_ASSERT(mpWidgetApplication);
    return mpWidgetApplication;
}




