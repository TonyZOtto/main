#include "QQPoint.h"

#include <climits>

QQPoint::QQPoint() : QPoint(INT_MIN, INT_MIN) {;}
QQPoint::QQPoint(const QPoint other) : QPoint(other) {;}
QQPoint::QQPoint(const QQSize aSize, const Index ix)
    { x(ix % aSize.width()), y(ix / aSize.width()); }
QQPoint::QQPoint(const int aX, const int aY) : QPoint(aX, aY) {;}

QQPoint::QQPoint(const int aX, const int aY, const float aScaleF)
{
    setX(qRound(float(aX) * aScaleF)),
    setY(qRound(float(aY) * aScaleF));
}

bool QQPoint::isNull()
{
    return (INT_MIN == x()) && (INT_MIN == y());
}

QQPoint QQPoint::up() const
{
    return QQPoint(x(), y() - 1);
}
