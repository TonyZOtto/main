#include "BaseMainWindow.h"

#include "WidgetApplication.h"

BaseMainWindow::BaseMainWindow(WidgetApplication *wapp)
    : QMainWindow{nullptr}
{
    setObjectName("BaseMainWindow:" + wapp->applicationName());
}
