#include "ConsoleApplication.h"

#include <QtDebug>
#include <QCoreApplication>

#include "BaseApplication.h"
#include "ConsoleStdIO.h"

ConsoleApplication::ConsoleApplication(int argc, char *argv[], BaseApplication *parent)
    : BaseApplication(argc, argv, BaseApplication::Console)
    , mpBaseApplication(parent)
    , mpStdIO(new ConsoleStdIO(this))
{
    setObjectName("ConsoleApplication:" + QCoreApplication::applicationName());
    qInfo() << Q_FUNC_INFO << objectName();
}

void ConsoleApplication::initialize()
{
    base()->initialize();
}

void ConsoleApplication::configure()
{
    base()->configure();

}

void ConsoleApplication::start()
{
    base()->start();

}

void ConsoleApplication::finish()
{
    base()->finish();

}

