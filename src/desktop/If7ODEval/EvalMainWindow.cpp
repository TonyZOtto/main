#include "EvalMainWindow.h"

#include <WidgetApplication.h>

#include "SplashPage.h"

EvalMainWindow::EvalMainWindow(WidgetApplication *wapp)
    : StackedMainWindow(wapp)
{
    setObjectName("MainWindow:" + wapp->applicationName());
    addPage(new SplashPage(this));
    update();
}

EvalMainWindow::~EvalMainWindow() {;}
