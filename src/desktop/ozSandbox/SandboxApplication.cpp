#include "SandboxApplication.h"

#include <ApplicationHelper.h>

#include "SandboxEngine.h"
#include "SandboxMainWindow.h"

SandboxApplication::SandboxApplication(int &argc, char **argv)
    : QApplication{argc, argv}
    , mpHelper(new ApplicationHelper(this))
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("SandboxApplication:" + applicationName());
}

void SandboxApplication::initialize()
{
    qInfo() << Q_FUNC_INFO;

    mpEngine = new SandboxEngine(this);
    engine()->initialize();

    connect(this, &SandboxApplication::initialized,
            this, &SandboxApplication::objconnect);

    emit initialized();
}

void SandboxApplication::objconnect()
{
    qInfo() << Q_FUNC_INFO;
    connect(this, &SandboxApplication::objconnected,
            mainWindow(), &SandboxMainWindow::initialize);
    connect(mainWindow(), &SandboxMainWindow::initialized,
            this, &SandboxApplication::configure);
    connect(this, &SandboxApplication::configured,
            mainWindow(), &SandboxMainWindow::configure);
    connect(mainWindow(), &SandboxMainWindow::configured,
            this, &SandboxApplication::setup);
    connect(this, &SandboxApplication::setuped,
            mainWindow(), &SandboxMainWindow::setup);
    connect(mainWindow(), &SandboxMainWindow::setuped,
            this, &SandboxApplication::start);
    connect(this, &SandboxApplication::started,
            mainWindow(), &SandboxMainWindow::start);
    emit objconnected();
}

void SandboxApplication::configure()
{
    qInfo() << Q_FUNC_INFO;
    // TODO: Process CommandLine
    // TODO: Open ApplicationSettings from OrgAppIni and CLArgs
    // TODO: Read SandboxData from settings
    engine()->configure();
    emit configured();
}

void SandboxApplication::setup()
{
    qInfo() << Q_FUNC_INFO;
    engine()->setup();
    QImage tSubjectImage(":/image/MM512A.jpg");
    engine()->setSubjectPhoto(BasePhoto(Photo::Color, tSubjectImage));
    emit setuped();
}

void SandboxApplication::start()
{
    qInfo() << Q_FUNC_INFO;
    emit started();
}

SandboxScene *SandboxApplication::scene()
{
    return mainWindow()->scene();
}

CommandLine *SandboxApplication::commandLine()
{
    return appHelper()->commandLine();
}

AppSettings *SandboxApplication::settings()
{
    return appHelper()->appSettings();
}
