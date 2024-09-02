#include "EvalMainWindow.h"

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

void EvalMainWindow::setup()
{
    qInfo() << Q_FUNC_INFO;
    showMaximized();
    updateGeometry();
    StackedMainWindow::setup();
    mpSplashPage->setup(size());
    mpLogPage->setup(size());
    mpLogPage->addLine("Log Started");
    mpAcquirePage->setup(size());
    addPage(mpSplashPage);
    addPage(mpLogPage);
    addPage(mpAcquirePage);
    setCurrent(0);
    update();
}
