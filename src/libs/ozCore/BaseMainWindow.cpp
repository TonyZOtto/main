#include "BaseMainWindow.h"

#include <QScreen>
#include <QResizeEvent>

#include <Settings.h>

#include "Debug.h"
#include "QQPoint.h"
#include "WidgetApplication.h"

#include <ApplicationHelper.h>

BaseMainWindow::BaseMainWindow(WidgetApplication *wapp)
    : QMainWindow{nullptr}
    , mpCentralWidget(new QWidget(this))
{
    Q_ASSERT(mpCentralWidget);
    qInfo() << Q_FUNC_INFO << Qt::hex << APPH;
    setObjectName("BaseMainWindow:" + wapp->applicationName());
    APPH->set(this);
    mpCentralWidget->setObjectName("CentralWidget");
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
    QQSize tBaseSize = mConfigMap.value("BaseSize").toSize();
    qInfo() << Q_FUNC_INFO << mConfigMap << size() << tBaseSize;
    if (tBaseSize.isValid())
        resize(tBaseSize);
    if (mConfigMap.value("Maximized", false).toBool())
        showMaximized();
    else if (mConfigMap.value("Minimized", false).toBool())
        showMinimized();
    else
        showNormal();
    setCentralWidget(mpCentralWidget);
}

