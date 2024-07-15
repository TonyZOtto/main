#pragma once
#include "ozCore.h"

#include <QRect>
#include <QSize>

#include "QQPoint.h"
#include "QQSize.h"

class OZCORE_EXPORT SCRect
{
public: // types
    enum Anchor { TopLeft = 0, Center, };

public: // ctors
    SCRect();
    SCRect(const int aDim);
    SCRect(const QSize aSize);
    SCRect(const QRect aRect);
    SCRect(const QSize aSize, const QPoint aCenter);

public: // const
    QQSize size() const;
    int width() const;
    int height() const;
    QRect toQRect(const Anchor aAnchor=TopLeft) const;

private:
    QQSize mSize;
    QQPoint mCenter;
};

inline QQSize SCRect::size() const { return mSize; }
