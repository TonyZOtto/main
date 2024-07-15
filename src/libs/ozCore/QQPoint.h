#pragma once
#include "ozCore.h"

#include <QPoint>

#include "QQSize.h"
#include "Types.h"

class OZCORE_EXPORT QQPoint : public QPoint
{
public:
    QQPoint();
    QQPoint(const QPoint other);
    QQPoint(const QQSize aSize, const Index ix);
    QQPoint(const int aX, const int aY);

public:
    void x(const int aX) { setX(aX); }
    void y(const int aY) { setY(aY); }
};
