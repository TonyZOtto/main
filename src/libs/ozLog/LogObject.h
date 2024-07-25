#pragma once

#include <QObject>

class Log : public QObject
{
    Q_OBJECT

public: // types
    enum Level
    {
        $null           =   0,
        Minimum,        //  1
        Level02,        //  2
        TraceFnArg,     //  3
        TraceFnRtn,     //  4
        TrafeFnExit,    //  5
        TraceFnEnter,   //  6
        InfoTrivial,    //  7
        InfoDetail,     //  8
        Level09,        //  9
        TraceDump,      // 10
        TraceValue,     // 11
        TraceObject,    // 12
        Information,    // 13
        TraceDebug,     // 14
        TraceLow,       // 15
        Level16,        // 16
        InfoProgress,   // 17
        Trace18,        // 18
        TraceMedium,    // 19
        InfoStart,      // 20
        TraceStart,     // 21
        TraceHigh,      // 22
        TraceWarning,   // 23
        InfoWarning,    // 24
        Level25,        // 25
        TraceFocus,     // 26
        Level27,        // 27
        Error,          // 28
        ProcessFatal,   // 29
        Level30,        // 30
        SystemFatal     // 31
    };

public: // ctors
    explicit Log(QObject *parent = nullptr);

public slots:

signals:

public: // const

public: // non-const

private:

};
