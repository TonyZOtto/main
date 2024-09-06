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
    emit initialized();
}

void BaseMainWindow::configure()
{
    qInfo() << Q_FUNC_INFO;
    // TODO Anything
    emit configured();

}

void BaseMainWindow::setup()
{
    qInfo() << Q_FUNC_INFO;
    // TODO Anything
    emit setuped();

}
