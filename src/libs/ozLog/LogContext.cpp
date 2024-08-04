#include "LogContext.h"


LogFunctionInfo LogContext::functionInfo() const
{
    return LogFunctionInfo(mFuncInfo);
}

LogFileInfo LogContext::fileInfo() const
{
    return LogFileInfo(mFileName);
}

QString LogContext::categoryName() const
{
    return QString(mCatName);
}

unsigned int LogContext::fileLine() const
{
    return mFileLine;
}
