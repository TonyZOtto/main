#include "EngineMainWindow.h"

#include <QCoreApplication>

#include "EngineApplication.h"

EngineMainWindow::EngineMainWindow(EngineApplication *pApp)
    : QMainWindow(nullptr)
    , mpApplication(pApp)
{
    setObjectName("EngineMainWindow"
                  + QCoreApplication::applicationName());
}

EngineMainWindow::~EngineMainWindow() {}

void EngineMainWindow::initialize()
{

    setWindowTitle("INDIface Six Engine");

    emit initialized();
}
