#include "BaseMainWindow.h"

#include <QScreen>

#include "WidgetApplication.h"

BaseMainWindow::BaseMainWindow(WidgetApplication *wapp)
    : QMainWindow{nullptr}
{
    setObjectName("BaseMainWindow:" + wapp->applicationName());
}

void BaseMainWindow::initialize()
{
    qInfo() << Q_FUNC_INFO;
    // TODO Anything
}

void BaseMainWindow::configure()
{
    qInfo() << Q_FUNC_INFO;
    // TODO Anything
}

void BaseMainWindow::setup()
{
    qInfo() << Q_FUNC_INFO;
    // TODO Anything
}
