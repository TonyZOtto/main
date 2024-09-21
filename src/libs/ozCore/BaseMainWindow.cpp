#include "BaseMainWindow.h"

#include <QScreen>
#include <QResizeEvent>

#include <Settings.h>

#include "Debug.h"
#include "WidgetApplication.h"

#include <ApplicationHelper.h>

BaseMainWindow::BaseMainWindow(WidgetApplication *wapp)
    : QMainWindow{nullptr}
{
    qInfo() << Q_FUNC_INFO << Qt::hex << APPH;
    setObjectName("BaseMainWindow:" + wapp->applicationName());
    APPH->set(this);
}

void BaseMainWindow::initialize()
{
    qInfo() << Q_FUNC_INFO;
    connect(this, &BaseMainWindow::resized,
            this, &BaseMainWindow::handleResize);
}

void BaseMainWindow::configure()
{
    mConfigMap = APPH->settings()->map("MainWindow");
    qInfo() << Q_FUNC_INFO << mConfigMap;
}

void BaseMainWindow::setup()
{
    qInfo() << Q_FUNC_INFO << mConfigMap;
    if (mConfigMap.value("Maximized", false).toBool())
        showMaximized();
    else if (mConfigMap.value("Minimized", false).toBool())
        showMinimized();
    else
        showNormal();
}

void BaseMainWindow::handleResize(const QQSize newSize)
{
    qInfo() << Q_FUNC_INFO  << objectName() << mainSize() << newSize;
    WEXPECT(mainSize() == newSize);
}

void BaseMainWindow::resizeEvent(QResizeEvent *event)
{
    Q_ASSERT(event);
    mMainSize = event->size();
    emit resized(mMainSize);
}
