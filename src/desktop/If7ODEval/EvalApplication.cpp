#include "EvalApplication.h"

#include <ApplicationHelper.h>
Q_GLOBAL_STATIC(ApplicationHelper, APPH)


EvalApplication::EvalApplication(int &argc, char **argv)
    : WidgetApplication(argc, argv)
{
    setObjectName("EvalApplication");
}

void EvalApplication::initialize()
{
    APPH()->initialize();
}
