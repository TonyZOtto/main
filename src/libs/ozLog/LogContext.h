#pragma once

#include <QByteArray>
#include <QString>

#include "LogFileInfo.h"
#include "LogFunctionInfo.h"

class LogContext
{
public: // ctors
    LogContext() {;}
    LogContext(const char * pchFuncInfo,
               const char * pchFileName,
               const char * pchCatName,
               const unsigned fileLine);

public: // const
    LogFunctionInfo functionInfo() const;
    LogFileInfo fileInfo() const;
    QString categoryName() const;
    unsigned fileLine() const;

private:
    QByteArray mFuncInfo;
    QByteArray mFileName;
    QByteArray mCatName;
    unsigned mFileLine;
};
