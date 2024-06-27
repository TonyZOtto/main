#pragma once
#include "eIRexe.h"

#include <QString>
#include <QVersionNumber>

#include "../eIRbase/AText.h"
#include "../eIRcore/QQFileInfo.h"
#include "FunctionInfo.h"
#include "LogObject.h"

typedef Log::Level LogLevel;

class EIREXE_EXPORT Context
{
public: // ctors
    Context() {;}
    Context(const char * pchFuncInfo,
            const char * pchFileName,
            const unsigned fileLine,
            const LogLevel lvl);

public: // const
    FunctionInfo functionInfo() const;
    QQFileInfo fileInfo() const;
    unsigned fileLine() const;
    QVersionNumber versionNumber() const;
    Log::Level level() const;

private:
    AText mQFuncInfo;
    AText mFileName;
    unsigned mFileLine;
    Log::Level mLogLevel;
    QVersionNumber mVersionNumber;
};
