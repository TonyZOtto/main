#include "Context.h"


FunctionInfo Context::functionInfo() const
{
    return FunctionInfo(mFuncInfo);
}

QQFileInfo Context::fileInfo() const
{
    return QQFileInfo(mFileName);
}

QString Context::category() const
{
    return mCategory.toString();
}

unsigned int Context::fileLine() const
{
    return mFileLine;
}
