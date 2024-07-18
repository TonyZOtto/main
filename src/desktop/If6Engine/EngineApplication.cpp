#include "EngineApplication.h"

#include <QTimer>

#include "EngineMainWindow.h"

EngineApplication::EngineApplication(int &argc, char **argv)
    : QApplication(argc, argv)
{
    setObjectName("EngineApplication:" + applicationName());
    QTimer::singleShot(500, this, &EngineApplication::initialize);
}

void EngineApplication::initialize()
{
    connect(this, &EngineApplication::initialized,
            mainWindow(), &EngineMainWindow::initialize);
    emit initialized();
}
