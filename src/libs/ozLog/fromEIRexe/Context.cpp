#include "Context.h"

#include "../eirBase/VersionInfo.h"

Context::Context(const char *pchFuncInfo, const char *pchFileName,
                 const unsigned int fileLine, const LogLevel lvl)
{
    mQFuncInfo = pchFuncInfo, mFileName = pchFileName,
        mFileLine = fileLine, mLogLevel = lvl,
        mVersionNumber = VersionInfo::appVersion();
}

FunctionInfo Context::functionInfo() const
{
    return FunctionInfo(mQFuncInfo);
}

QQFileInfo Context::fileInfo() const
{
    return QQFileInfo(mFileName.toString());
}

unsigned int Context::fileLine() const
{
    return mFileLine;
}

QVersionNumber Context::versionNumber() const
{
    return mVersionNumber;
}

Log::Level Context::level() const
{
    return mLogLevel;
}
