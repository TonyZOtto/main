#include "BaseMainWindow.h"

#include <QScreen>
#include <QResizeEvent>

#include <Settings.h>

#include "WidgetApplication.h"

#include <ApplicationHelper.h>

QQSize BaseMainWindow::smScreenSize;

BaseMainWindow::BaseMainWindow(WidgetApplication *wapp)
    : QMainWindow{nullptr}
{
    qInfo() << Q_FUNC_INFO << Qt::hex << APPH;
    connect(this, &BaseMainWindow::resized,
            this, &BaseMainWindow::doResize);
    setObjectName("BaseMainWindow:" + wapp->applicationName());
    APPH->set(this);
}

void BaseMainWindow::initialize()
{
    qInfo() << Q_FUNC_INFO;
}

void BaseMainWindow::configure()
{
    qInfo() << Q_FUNC_INFO;
    mConfigMap = APPH->settings()->map("MainWindow");
    // TODO Anything
}

void BaseMainWindow::setup()
{
    qInfo() << Q_FUNC_INFO;
    if (mConfigMap.value("Maximized", false).toBool())
        showMaximized();
    else if (mConfigMap.value("Minimized", false).toBool())
        showMinimized();
    else
        showNormal();

    // TODO Anything
}

void BaseMainWindow::doResize(const QQSize newSize)
{
    qInfo() << Q_FUNC_INFO  << objectName() << newSize;
    Q_ASSERT(mainSize() == newSize);
}

QQSize BaseMainWindow::screenSize() const
{
    QQSize result = smScreenSize;
    if (result.isNull())
    {
        QScreen * pScreen = QGuiApplication::screens()[0];
        result = pScreen->availableSize();
    }
    qDebug() << Q_FUNC_INFO << result;
    return result;
}

void BaseMainWindow::resizeEvent(QResizeEvent *event)
{
    Q_ASSERT(event);
    mMainSize = event->size();
    emit resized(mMainSize);
}
