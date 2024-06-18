#pragma once

#include <QString>
#include <QString>

#include "../ozCore/AText.h"
#include "../ozCore/QQFileInfo.h"
#include "FunctionInfo.h"

class Context
{
public: // ctors
    Context() {;}
    Context(const char * pchFuncInfo, const char * pchFileName,
            const char * pchCategory, const unsigned fileLine);

public: // const
    FunctionInfo functionInfo() const;
    QQFileInfo fileInfo() const;
    QString category() const;
    unsigned fileLine() const;

private:
    AText mFuncInfo;
    AText mFileName;
    AText mCategory;
    unsigned mFileLine;
};
