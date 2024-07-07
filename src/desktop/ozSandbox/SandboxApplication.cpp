#include "SandboxApplication.h"

#include <MainSettings.h>

#include "SandboxEngine.h"

SandboxApplication::SandboxApplication(int &argc, char **argv)
    : QApplication{argc, argv}
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

}

void SandboxApplication::start()
{

}
