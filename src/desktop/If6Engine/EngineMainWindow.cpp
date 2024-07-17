#include "EngineMainWindow.h"

EngineMainWindow::EngineMainWindow(QWidget *parent)
    : QMainWindow(parent)
{}

EngineMainWindow::~EngineMainWindow() {}

void EngineMainWindow::initialize()
{

    emit initialized();
}
