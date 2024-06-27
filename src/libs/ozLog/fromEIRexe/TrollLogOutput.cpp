#include "TrollLogOutput.h"

#include "LogItem.h"
#include "LogMsgType.h"

TrollLogOutput::TrollLogOutput(const OutputLogUrl &aUrl, QObject *parent)
    : BaseLogOutput{aUrl, parent}
{
    setObjectName("TrollLogOutput");
}

bool TrollLogOutput::open(const OutputLogUrl &aUrl)
{
    url(aUrl), mode(QIODevice::WriteOnly | QIODevice::Append);
    return true;
}

bool TrollLogOutput::write(const LogItem &aItem)
{
    static QString stFirstLine;
    const QStringList cLines = aItem.format(Log::TextFileMultiOutput).toStringList();
    if (stFirstLine != cLines.first())
    {
        write(aItem.msgtype(), cLines.first());
        stFirstLine = cLines.first();
    }
    write(aItem.msgtype(), cLines.mid(1));
    return true;
}

void TrollLogOutput::write(const LogMsgType aMsgType, const QStringList &aStrings)
{
    foreach (const QString cString, aStrings)
        write(aMsgType, cString);
}

void TrollLogOutput::write(const LogMsgType aMsgType, const QString &aString)
{
    write(aMsgType, qPrintable(aString));
}

void TrollLogOutput::write(const LogMsgType aMsgType, const char *pch)
{
    switch (aMsgType.type())
    {
    case LogMsgType::Info:      qInfo("%s", pch);       break;
    case LogMsgType::Debug:     qDebug("%s", pch);      break;
    case LogMsgType::Warning:   qWarning("%s", pch);    break;
    case LogMsgType::Error:     qCritical("%s", pch);   break;
    case LogMsgType::Fatal:     qFatal("%s", pch);      break;
    default:                    qDebug("%s", pch);      break;
    }
}
