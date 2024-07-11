#include "SandboxApplication.h"

#include <ApplicationHelper.h>

#include "SandboxEngine.h"
#include "SandboxMainWindow.h"

SandboxApplication::SandboxApplication(int &argc, char **argv)
    : QApplication{argc, argv}
    , mpHelper(new ApplicationHelper(this))
{
    setObjectName("SandboxApplication:" + applicationName());
}

void SandboxApplication::initialize()
{
    mpEngine = new SandboxEngine(this);
    Q_CHECK_PTR(mpEngine);
    mpEngine->initialize();

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
    // TODO: Process CommandLine
    // TODO: Open ApplicationSettings from OrgAppIni and CLArgs
    // TODO: Read SandboxData from settings
}

void SandboxApplication::setup()
{
    engine()->setup();
    QImage tSubjectImage(":/image/MM512A.jpg");
    engine()->setSubjectPhoto(BasePhoto(Photo::Color, tSubjectImage));
}

void SandboxApplication::start()
{

}

SandboxScene *SandboxApplication::scene()
{
    return mainWindow()->scene();
}

CommandLine *SandboxApplication::commandLine()
{
    return helper()->commandLine();
}

AppSettings *SandboxApplication::settings()
{
    return helper()->appSettings();
}
