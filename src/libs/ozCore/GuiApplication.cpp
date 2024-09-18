#include "GuiApplication.h"

#include "ApplicationHelper.h"

GuiApplication::GuiApplication(int &argc, char **argv)
    : QGuiApplication(argc, argv)
{
    setObjectName("GuiApplication");
}


