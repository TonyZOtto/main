#include "BaseApplication.h"

#include <QApplication>
#include <QCoreApplication>
#include <QGuiApplication>

#include "QQFileInfo.h"
#include "ApplicationSettings.h"
#include "ConsoleApplication.h"
#include "DesktopApplication.h"
#include "WidgetApplication.h"
#include "CommandLine.h"


BaseApplication::BaseApplication(int argc, char *argv[], const Class appClass)
    : QObject(nullptr)
    , mpCommandLine(new CommandLine(argc, argv, this))
    , cmpApplicationSettings(new ApplicationSettings(this))
    , cmExeFileInfo(QQFileInfo(*argv))
{
    switch (appClass)
    {
    case Console:
        mpQCoreApplication = new QCoreApplication(argc, argv);
        break;

    default:
        Q_ASSERT(!"MUSTDO"); // MUSTDO Desktop & Widget
        break;
    }
    setObjectName("BaseApplication:" + mpQCoreApplication->applicationName());
    qInfo() << Q_FUNC_INFO << objectName();

}

void BaseApplication::initialize()
{
    // TODO TBD
    processOptions();
    commandLine()->process();
}

void BaseApplication::addOption()
{
    // MUSTDO
}

void BaseApplication::processOptions()
{
    // MUSTDO

}



