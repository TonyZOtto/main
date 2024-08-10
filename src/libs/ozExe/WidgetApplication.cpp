#include "WidgetApplication.h"

#include "ApplicationHelper.h"

WidgetApplication::WidgetApplication(int &argc, char **argv)
    : QApplication(argc, argv)
    , mpHelper(new ApplicationHelper(this))
{
    setObjectName("WidgetApplication");
}

