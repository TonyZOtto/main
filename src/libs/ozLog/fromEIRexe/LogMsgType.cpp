#include "LogMsgType.h"

LogMsgType::LogMsgType() {}

LogMsgType::LogMsgType(const int i)
{
    mType = isValid(i) ? Type(i) : $null;
}

bool LogMsgType::isValid(const int i)
{
    return i >= $minValid && i <= $maxValid;
}
