#include "EvalMainWindow.h"

#include <WidgetApplication.h>

#include "SplashPage.h"

EvalMainWindow::EvalMainWindow(WidgetApplication *wapp)
    : StackedMainWindow(wapp)
    , mpSplashPage(new SplashPage(this))
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("MainWindow:" + wapp->applicationName());
}

EvalMainWindow::~EvalMainWindow() {;}

void EvalMainWindow::setup()
{
    qInfo() << Q_FUNC_INFO;
    showMaximized();
    StackedMainWindow::setup();
    mpSplashPage->setup(size());
    addPage(mpSplashPage);
    update();
}
