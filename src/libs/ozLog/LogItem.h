#pragma once

#include <QSharedDataPointer>

class LogContext;
class LogItemData;

class LogItem
{
public: // specific ctors
    LogItem(const LogContext &ctx);

public: // shared data members
    LogItem();
    LogItem(const LogItem &);
    LogItem &operator=(const LogItem &);
    ~LogItem();

private:
    QSharedDataPointer<LogItemData> data;
};
