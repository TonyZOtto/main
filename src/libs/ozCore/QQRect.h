#pragma once
#include "ozCore.h"

#include <QRect>

#include "QQPoint.h"
#include "QQSize.h"

class OZCORE_EXPORT QQRect : public QRect
{
public: // ctors
    QQRect();
    QQRect(const QQSize aSize);
    QQRect(const QQPoint aTLPt, const QQSize aSize);

public: // const

public: // non-const
    void set(const QQPoint aTLPt, const QQSize aSize);
};
