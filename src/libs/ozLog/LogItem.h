#pragma once

#include <QByteArray>
#include <QSharedDataPointer>
#include <QString>
#include <QStringList>
#include <QVariant>

class LogContext;
class LogItemData;

class LogItem
{
public: // specific ctors
    LogItem(const LogContext &ctx);

public: // shared data members
    LogItem();
    LogItem(const LogItem &);
    ~LogItem();
    LogItem &operator=(const LogItem &);

private:
    QSharedDataPointer<LogItemData> data;
};
