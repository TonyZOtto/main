#include "WidgetApplication.h"

#include "ApplicationHelper.h"

WidgetApplication::WidgetApplication(int &argc, char **argv)
    : QApplication(argc, argv)
{
    setObjectName("WidgetApplication");
}

void WidgetApplication::initialize()
{
    qInfo() << Q_FUNC_INFO;
    APPH->initialize();
    APPH->makeConnections();
    // TODO Anything else?
}

void WidgetApplication::configure()
{
    qInfo() << Q_FUNC_INFO;
    // TODO Anything
}

void WidgetApplication::setup()
{
    qInfo() << Q_FUNC_INFO;
    // TODO Anything
}

