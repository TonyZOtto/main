#include "EvalMainWindow.h"

#include <QScreen>

#include <ApplicationHelper.h>
#include <QQSize.h>
#include <Settings.h>
#include <Value.h>
#include <WidgetApplication.h>

#include "AcquirePage.h"
#include "LogPage.h"
#include "SplashPage.h"

EvalMainWindow::EvalMainWindow(WidgetApplication *wapp)
    : StackedMainWindow(wapp)
    , mpSplashPage(new SplashPage(this))
    , mpLogPage(new LogPage(this))
    , mpAcquirePage(new AcquirePage(this))
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("MainWindow:" + wapp->applicationName());
}

EvalMainWindow::~EvalMainWindow() {;}

void EvalMainWindow::initialize()
{
    qInfo() << Q_FUNC_INFO;
    StackedMainWindow::initialize();

    emit initialized();
}

void EvalMainWindow::configure()
{
    qInfo() << Q_FUNC_INFO;
#if 0
    QScreen * pScreen = QGuiApplication::primaryScreen();
    QQSize tScreenSize = pScreen->size();
    Value tPageUnderSizeValue(APPH->settings()->
                              get("MainWindow/PageUnderSize", QSize(30, 100)));
    QQSize tPageUnderSize = tPageUnderSizeValue.size();
    tScreenSize -= tPageUnderSize;
    tScreenSize -= QQSize(30, 0) // take out page tabbar
    pageSize(tScreenSize);
#endif
    emit configured();
}

void EvalMainWindow::setup()
{
    qInfo() << Q_FUNC_INFO;
    StackedMainWindow::setup();
    mpSplashPage->setup();
    mpLogPage->setup();
    mpLogPage->addLine("Log Started");
    mpAcquirePage->setup();
    addPage(mpSplashPage);
    addPage(mpLogPage);
    addPage(mpAcquirePage);
    setCurrent(0);
    update();
    emit setuped();
}

AcquirePage *EvalMainWindow::acquirePage()
{
    return (AcquirePage *)page("Acquire");
}
