#include "BaseMainWindow.h"

#include <QScreen>
#include <QResizeEvent>

#include <Settings.h>

#include "WidgetApplication.h"

#include <ApplicationHelper.h>

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

void BaseMainWindow::doResize(const QQSize newSize)
{
    qInfo() << Q_FUNC_INFO  << objectName() << newSize;
    Q_ASSERT(mainSize() == newSize);
}

QQSize BaseMainWindow::screenSize(const Index kScreen) const
{
    QQSize result;
    QList<QScreen *> tScreenList = QGuiApplication::screens();
    if (kScreen >= 0 && kScreen < tScreenList.count())
    {
        QScreen * pScreen = tScreenList[kScreen];
        result = pScreen->availableSize();
    }
    qInfo() << Q_FUNC_INFO << kScreen << result << "of" << tScreenList.count();
    return result;
}

void BaseMainWindow::resizeEvent(QResizeEvent *event)
{
    Q_ASSERT(event);
    mMainSize = event->size();
    emit resized(mMainSize);
}
