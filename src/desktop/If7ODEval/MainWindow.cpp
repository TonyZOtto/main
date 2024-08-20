#include "MainWindow.h"

#include <WidgetApplication.h>

MainWindow::MainWindow(WidgetApplication *wapp)
    : GridMainWindow(wapp)
{
    setObjectName("MainWindow:" + wapp->applicationName());
}

MainWindow::~MainWindow() {;}
