#include "CommandLine.h"

#include <QCoreApplication>
#include <QFileInfo>

CommandLine::CommandLine()
    : QObject{qApp}
{
    setObjectName("CommandLine");
}

CommandLine::CommandLine(int argc, char *argv[])
    : QObject{qApp}
    , cmExeFileName(*argv)
    , cmRawArgumentList(parseRawArguments(argc, argv))
{
    setObjectName("CommandLine:" + QFileInfo(cmExeFileName).baseName());
}


void CommandLine::process()
{

}

// static
QStringList CommandLine::parseRawArguments(int argc, char *argv[])
{
    QStringList result;
    for (int ix = 1; ix < argc; ++ix)
        result.append(QString(argv[ix]));
    return result;
}
