#include "CommandLine.h"

#include <QCoreApplication>
#include <QFileInfo>


#include "ApplicationHelper.h"

CommandLine::CommandLine(ApplicationHelper *parent)
    : QObject(parent)
    , mpHelper(parent)
    , cmRawArgumentList(QCoreApplication::arguments())
    , cmExeFileInfo(cmRawArgumentList.first())
{
    setObjectName("CommandLine");
}

CommandLine::CommandLine(const QStringList aRawArgList, ApplicationHelper *parent)
    : QObject(parent)
    , mpHelper(parent)
    , cmRawArgumentList(aRawArgList)
    , cmExeFileInfo(cmRawArgumentList.first())
{
    setObjectName("CommandLine");
}

CommandLine::CommandLine(int argc, char *argv[], ApplicationHelper * parent)
    : QObject(parent)
    , mpHelper(parent)
    , cmRawArgumentList(parseRawArguments(argc, argv))
    , cmExeFileInfo(cmRawArgumentList.first())
{
    setObjectName("CommandLine");
}

void CommandLine::process()
{
    foreach (const QString cArg, cmRawArgumentList.mid(1))
    {
        emit processing(cArg);
        if (cArg.startsWith('@'))
            processIncludeFile(cArg.mid(1));
        else if (cArg.startsWith('$'))
            processSettingValue(cArg.mid(1));
        else if (cArg.startsWith('%'))
            processSettingsName(cArg.mid(1));
        else
            mPositionalArguments.append(cArg),
            mPositionalFileInfos.append(QFileInfo(cArg));
    }
}

void CommandLine::processIncludeFile(const QString atsArg)
{

}

void CommandLine::processSettingValue(const QString dlrArg)
{

}

void CommandLine::processSettingsName(const QString pctArg)
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
