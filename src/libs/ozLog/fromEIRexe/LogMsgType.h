#pragma once

#include <QtGlobal>

class LogMsgType
{
public: // types
    enum Type
    {
        $null       = -1,
        Debug       = QtDebugMsg,
        Warning     = QtWarningMsg,
        Error       = QtCriticalMsg,
        Fatal       = QtFatalMsg,
        Info        = QtInfoMsg,
        $minValid   = Debug,
        $maxValid   = Info,
    };

public: // ctors
    LogMsgType();
    LogMsgType(const QtMsgType qmt);
    LogMsgType(const int i);
//    LogMsgType(const LogMsgType &other);

public: // const
    Type type() const;

public: // non-const
    void type(const int i) const;

public: // static
    static bool isValid(const int i);

private:
    Type mType;
};

inline LogMsgType::Type LogMsgType::type() const
{
    return mType;
}
