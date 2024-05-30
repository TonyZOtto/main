#include "MainWindow.h"

#include <QApplication>
#include <QIcon>

#include "SandboxToolbar.h"
#include "SandboxWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mpQuitAction(new QAction(QIcon(":/icon/noun-quit-1331221.svg"), "Quit", this))
    , mpSandboxWidget(new SandboxWidget(this))
    , mpSandboxToolbar(new SandboxToolbar(this))
{
    setObjectName("ozSandbox:MainWindow");
    connect(mpQuitAction, &QAction::triggered, qApp, &QApplication::quit);
    mpSandboxToolbar->addAction(mpQuitAction);
    addToolBar(mpSandboxToolbar);
    setCentralWidget(mpSandboxWidget);
}

MainWindow::~MainWindow()
{
}
