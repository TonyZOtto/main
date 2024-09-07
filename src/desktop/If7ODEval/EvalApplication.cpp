#include "EvalApplication.h"

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

void EvalApplication::configure()
{
    qInfo() << Q_FUNC_INFO;
    emit configured();
}

void EvalApplication::setup()
{
    qInfo() << Q_FUNC_INFO;
    emit setuped();
}
