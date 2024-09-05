#include "CommandLine.h"

#include <QByteArray>
#include <QByteArrayList>
#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QVariant>


#include "ApplicationHelper.h"
#include "SettingsName.h"

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
    qInfo() << Q_FUNC_INFO << cmRawArgumentList;
    setObjectName("CommandLine");
}

void CommandLine::process()
{
    qInfo() << Q_FUNC_INFO << cmRawArgumentList;
    mSettingsName.setDefaltOrgApp();
    mProcessingArguments = cmRawArgumentList.mid(1);
    while ( ! mProcessingArguments.isEmpty())
    {
        const QString cArg = mProcessingArguments.takeFirst();
        qDebug() << "process()ing:" << cArg;
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
    qDebug() << mSettingValuesMap
             << mSettingsName.toString()
             << mPositionalArguments;
}

void CommandLine::processIncludeFile(const QString atsArg)
{
    qInfo() << Q_FUNC_INFO << atsArg;
    QFile * pCommandFile = new QFile(atsArg, parent());
    Q_ASSERT(pCommandFile);
    if (pCommandFile->open(QIODevice::ReadOnly
                           | QIODevice::Text))
    {
        QByteArray tBytes = pCommandFile->readAll();
        QByteArrayList tByteLines = tBytes.split('\n');
        pCommandFile->close();
        pCommandFile->deleteLater();
        foreach (QByteArray tLine, tByteLines)
        {
            if (tLine.endsWith('\r'))
                tLine.chop(1);
            mProcessingArguments.prepend(tLine);
        }
    }
}

void CommandLine::processSettingValue(const QString dlrArg)
{
    qInfo() << Q_FUNC_INFO << dlrArg;
    const Index cEqualsIndex = dlrArg.indexOf('=');
    Key tKey;
    QVariant tValue;
    if (cEqualsIndex < 0)
    {
        tKey.set(dlrArg);
        tValue = true;
    }
    else if (cEqualsIndex == dlrArg.length() - 1)
    {   // trailing '='
        tKey.set(dlrArg.chopped(1));
        tValue = QString();
    }
    else
    {
        tKey.set(dlrArg.left(cEqualsIndex - 1));
        tValue = dlrArg.mid(cEqualsIndex + 1);
    }
    mSettingValuesMap.insert(tKey, tValue);
}

void CommandLine::processSettingsName(const QString pctArg)
{
    qInfo() << Q_FUNC_INFO << pctArg;
    const SettingsName cSName(pctArg);
    if (cSName.type() != SettingsName::$null)
        mSettingsName = cSName;
}

// static
QStringList CommandLine::parseRawArguments(int argc, char *argv[])
{
    QStringList result;
    for (int ix = 1; ix < argc; ++ix)
        result.append(QString(argv[ix]));
    qInfo() << Q_FUNC_INFO << result;
    return result;
}
