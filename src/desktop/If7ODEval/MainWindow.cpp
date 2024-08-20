#include "MainWindow.h"

#include <WidgetApplication.h>

MainWindow::MainWindow(WidgetApplication *wapp)
    : StackedMainWindow(wapp)
{
    setObjectName("MainWindow:" + wapp->applicationName());
}

MainWindow::~MainWindow() {;}
