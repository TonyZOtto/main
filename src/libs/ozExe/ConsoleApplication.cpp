#include "ConsoleApplication.h"

#include "ApplicationHelper.h"

ConsoleApplication::ConsoleApplication(int &argc, char **argv)
    : QCoreApplication(argc, argv)
    , mpHelper(new ApplicationHelper(this))
{
    setObjectName("ConsoleApplication");
}

