#include "WidgetApplication.h"

#include "ApplicationHelper.h"

WidgetApplication::WidgetApplication(int &argc, char **argv)
    : QApplication(argc, argv)
{
    setObjectName("WidgetApplication");
}

