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
    // TODO Anything
}

void BaseMainWindow::setup()
{
    qInfo() << Q_FUNC_INFO;
    // TODO Anything
}

void BaseMainWindow::doResize()
{
    qInfo() << Q_FUNC_INFO  << objectName() << mainSize();

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
