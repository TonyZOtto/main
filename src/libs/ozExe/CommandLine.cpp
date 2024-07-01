#include "CommandLine.h"

#include "BaseApplication.h"

CommandLine::CommandLine(int argc, char *argv[], BaseApplication *parent)
    : QObject{parent}
    , cmExeFileName(*argv)
    , cmRawArgumentList(parseRawArguments(argc, argv))
{

}


void CommandLine::process()
{
    QStringList tInArgs, tOutArgs;

}

// static
QStringList CommandLine::parseRawArguments(int argc, char *argv[])
{
    QStringList result;
    for (int ix = 1; ix < argc; ++ix)
        result.append(QString(argv[ix]));
    return result;
}
