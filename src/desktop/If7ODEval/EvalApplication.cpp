#include "EvalApplication.h"

#include <ApplicationHelper.h>
#include <VersionInfo.h>

#include "../../version.h"
#include "version.h"

Q_GLOBAL_STATIC(ApplicationHelper, APPH)

EvalApplication::EvalApplication(int &argc, char **argv)
    : WidgetApplication(argc, argv)
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("EvalApplication");
}

void EvalApplication::initialize()
{   // called by main's SingleShot
    qInfo() << Q_FUNC_INFO;
    WidgetApplication::initialize();
    // TODO Anything else?
    emit initialized();
}

void EvalApplication::configure()
{
    qInfo() << Q_FUNC_INFO;
    WidgetApplication::configure();
    emit configured();
}

void EvalApplication::setup()
{
    qInfo() << Q_FUNC_INFO;
    WidgetApplication::setup();
    emit setuped();
}
