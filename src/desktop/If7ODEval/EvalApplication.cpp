#include "EvalApplication.h"

//#include <ApplicationHelper.h>
//Q_GLOBAL_STATIC(ApplicationHelper, APPH)


EvalApplication::EvalApplication(int &argc, char **argv)
    : WidgetApplication(argc, argv)
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("EvalApplication");
}

void EvalApplication::initialize()
{
    qInfo() << Q_FUNC_INFO;
    emit initialized();
}
