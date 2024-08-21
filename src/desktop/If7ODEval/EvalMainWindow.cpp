#include "EvalMainWindow.h"

#include <WidgetApplication.h>

#include "SplashPage.h"

EvalMainWindow::EvalMainWindow(WidgetApplication *wapp)
    : StackedMainWindow(wapp)
    , mpSplashPage(new SplashPage(this))
{
    setObjectName("MainWindow:" + wapp->applicationName());
}

EvalMainWindow::~EvalMainWindow() {;}

void EvalMainWindow::setup()
{
    showMaximized();
    StackedMainWindow::setup();
    mpSplashPage->setup(size());
    addPage(mpSplashPage);
    update();
}
