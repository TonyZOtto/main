#include "ConsoleApplication.h"

#include "ApplicationHelper.h"

ConsoleApplication::ConsoleApplication(int &argc, char **argv)
    : QCoreApplication(argc, argv)
{
    setObjectName("ConsoleApplication");
}

