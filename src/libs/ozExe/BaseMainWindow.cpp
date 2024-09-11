#include "BaseMainWindow.h"

#include <QScreen>

#include <Settings.h>

#include "WidgetApplication.h"

#include <ApplicationHelper.h>
Q_GLOBAL_STATIC(ApplicationHelper, APPH);

BaseMainWindow::BaseMainWindow(WidgetApplication *wapp)
    : QMainWindow{nullptr}
{
    setObjectName("BaseMainWindow:" + wapp->applicationName());
}

void BaseMainWindow::initialize()
{
    qInfo() << Q_FUNC_INFO;
    mMainUnderSizeValue = QQSize(30, 100);

}

void BaseMainWindow::configure()
{
    qInfo() << Q_FUNC_INFO;
    mMainUnderSizeValue = APPH->settings()->get("MainWindow/UnderSize");
    // TODO Anything
}

void BaseMainWindow::setup()
{
    qInfo() << Q_FUNC_INFO;
    // TODO Anything
}

QQSize BaseMainWindow::centralSize() const
{
    QQSize result;
    QWidget * pCentral = centralWidget();
    result = pCentral->size();
    qInfo() << Q_FUNC_INFO << pCentral->objectName() << result;
    return result;
}

QQSize BaseMainWindow::maximizedSize(const bool live)
{
    if (live || mMainSize.isNull())
    {
        QScreen * pScreen = QGuiApplication::primaryScreen();
        QQSize tScreenSize = pScreen->size();
        tScreenSize -= mMainUnderSizeValue.toSize();
        mMainSize = tScreenSize - mMainUnderSizeValue.toSize();
    }
    qInfo() << Q_FUNC_INFO << live << mMainSize;
    return mMainSize;
}
