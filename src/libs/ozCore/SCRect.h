#pragma once
#include "ozCore.h"

#include "QQPoint.h"
#include "QQSize.h"

class OZCORE_EXPORT SCRect
{
public: // ctors
    SCRect();
    SCRect(const QSize aSize);
    SCRect(const QSize aSize, const QPoint aCenter);

private:
    QQSize mSize;
    QQPoint mCenter;
};
