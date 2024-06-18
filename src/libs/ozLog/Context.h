#pragma once

#include <QByteArray>
#include <QString>

#include "FileInfo.h"
#include "FunctionInfo.h"

class Context
{
public: // ctors
    Context() {;}
    Context(const char * pchFuncInfo, const char * pchFileName,
            const char * pchCategory, const unsigned fileLine);

public: // const
    FunctionInfo functionInfo() const;
    FileInfo fileInfo() const;
    QString category() const;
    unsigned fileLine() const;

private:
    QByteArray mFuncInfo;
    QByteArray mFileName;
    QByteArray mCategory;
    unsigned mFileLine;
};
