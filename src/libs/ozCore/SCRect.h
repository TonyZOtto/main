#pragma once
#include "ozCore.h"

#include <QMetaType>
#include <QRect>
#include <QSize>
#include <QVariant>

#include "QQPoint.h"
#include "QQSize.h"
#include "SCRect.h"

class OZCORE_EXPORT SCRect
{
public: // types
    enum Anchor { TopLeft = 0, Center, };

public: // ctors
    SCRect(const int aDim);
    SCRect(const QSize aSize);
    SCRect(const QRect aRect);
    SCRect(const QSize aSize, const QPoint aCenter);

public: // const
    QQSize size() const;
    QQPoint center() const;
    bool isNull() const;
    int width() const;
    int height() const;
    QVariant toQVariant() const;
    operator QVariant () const { return toQVariant(); }
    QRect toQRect(const Anchor aAnchor=TopLeft) const;

private:
    QQSize mSize;
    QQPoint mCenter;

public: // QMetaType
    SCRect() = default;
    ~SCRect() = default;
    SCRect(const SCRect &) = default;
    SCRect &operator=(const SCRect &) = default;
};

Q_DECLARE_METATYPE(SCRect);

inline QQSize SCRect::size() const { return mSize; }
inline QQPoint SCRect::center() const { return mCenter; }

