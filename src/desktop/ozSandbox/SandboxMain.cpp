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
