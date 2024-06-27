#pragma once

#include <QObject>
#include "BaseLogOutput.h"

#include "LogMsgType.h"

class TrollLogOutput : public BaseLogOutput
{
    Q_OBJECT
public:
    explicit TrollLogOutput(const OutputLogUrl &aUrl, QObject *parent = nullptr);

public:
    virtual bool open(const OutputLogUrl &aUrl) override;
    virtual bool write(const LogItem &aItem) override;

private:
    void write(const LogMsgType aMsgType, const QStringList &aStrings);
    void write(const LogMsgType aMsgType, const QString &aString);
    void write(const LogMsgType aMsgType, const char *pch);
};
