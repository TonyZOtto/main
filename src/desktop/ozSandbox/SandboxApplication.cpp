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
            this, &SandboxApplication::configure);
    connect(this, &SandboxApplication::initialized,
            mainWindow(), &SandboxMainWindow::initialize);
    connect(this, &SandboxApplication::configured,
            this, &SandboxApplication::setup);
    connect(this, &SandboxApplication::setuped,
            this, &SandboxApplication::objconnect);
    connect(this, &SandboxApplication::objconnected,
            this, &SandboxApplication::start);
    emit initialized();
}

void SandboxApplication::configure()
{
    qInfo() << Q_FUNC_INFO;
    // TODO: Process CommandLine
    // TODO: Open ApplicationSettings from OrgAppIni and CLArgs
    // TODO: Read SandboxData from settings
    engine()->configure();
}

void SandboxApplication::setup()
{
    qInfo() << Q_FUNC_INFO;
    engine()->setup();
    QImage tSubjectImage(":/image/MM512A.jpg");
    engine()->setSubjectPhoto(BasePhoto(Photo::Color, tSubjectImage));
}

void SandboxApplication::start()
{
    qInfo() << Q_FUNC_INFO;

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
