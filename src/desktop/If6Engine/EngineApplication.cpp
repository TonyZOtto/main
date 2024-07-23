#include "EngineApplication.h"

#include <QTimer>

#include "EngineMainWindow.h"

EngineApplication::EngineApplication(int &argc, char **argv)
    : QApplication(argc, argv)
    , mpMainWindow(new EngineMainWindow(this))
{
    setObjectName("EngineApplication:" + applicationName());
    QTimer::singleShot(500, this, &EngineApplication::initialize);
}

void EngineApplication::initialize()
{
    connect(this, &EngineApplication::initialized,
            mainWindow(), &EngineMainWindow::initialize);
    connect(mainWindow(), &EngineMainWindow::initialized,
            mainWindow(), &EngineMainWindow::setup);
    emit initialized();
}

void EngineApplication::actQuit()
{
    QApplication::exit(1);
}

void EngineApplication::showMainWindow()
{
    mainWindow()->show();
}
