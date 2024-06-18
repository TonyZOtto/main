#include "Context.h"


FunctionInfo Context::functionInfo() const
{
    return FunctionInfo(mFuncInfo);
}

FileInfo Context::fileInfo() const
{
    return FileInfo(mFileName);
}

QString Context::category() const
{
    return QString(mCategory);
}

unsigned int Context::fileLine() const
{
    return mFileLine;
}
