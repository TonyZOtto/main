#include "GuiApplication.h"

#include "ApplicationHelper.h"

GuiApplication::GuiApplication(int &argc, char **argv)
    : QGuiApplication(argc, argv)
    , mpHelper(new ApplicationHelper(this))
{
    setObjectName("GuiApplication");
}


