#include "EvalMainWindow.h"

#include <WidgetApplication.h>

#include "LogPage.h"
#include "SplashPage.h"

EvalMainWindow::EvalMainWindow(WidgetApplication *wapp)
    : StackedMainWindow(wapp)
    , mpSplashPage(new SplashPage(this))
    , mpLogPage(new LogPage(this))
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
    addPage(mpSplashPage);
    addPage(mpLogPage);
    setCurrent(0);
    update();
}
