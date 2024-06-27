#include "BaseLogOutput.h"

BaseLogOutput::BaseLogOutput(QObject *parent)
    : QObject{parent}
{
    setObjectName("BaseLogOutput:NullURL");
}

BaseLogOutput::BaseLogOutput(const OutputLogUrl &url,
                             QObject *parent)
    : QObject(parent)
    , mUrl(url)
    , mOpenMode(QIODevice::NotOpen)
{
    setObjectName("BaseLogOutput:" + mUrl.toString());
}

bool BaseLogOutput::isFlag(const Log::LevelFlag level) const
{
    return flags().testFlag(level);
}

