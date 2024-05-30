#include "SandboxMain.h"

#include <QApplication>
#include <QIcon>

#include "SandboxActions.h"

SandboxMain::SandboxMain(QWidget *parent)
    : QMainWindow(parent)
    , mpSandboxActions(new SandboxActions(this))
{
    setObjectName("ozSandbox:MainWindow");
}

SandboxMain::~SandboxMain()
{
}

void SandboxMain::initialize()
{
    mpSandboxActions = new SandboxActions(this);
    Q_CHECK_PTR(mpSandboxActions);
    mpSandboxActions->initialize();
}

void SandboxMain::setup()
{
    Q_CHECK_PTR(mpSandboxActions);
    mpSandboxActions->setup();
}
