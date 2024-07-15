#include "QQPoint.h"

QQPoint::QQPoint() : QPoint(0, 0) {;}
QQPoint::QQPoint(const QPoint other) : QPoint(other) {;}
QQPoint::QQPoint(const QQSize aSize, const Index ix)
    { x(ix % aSize.width()), y(ix / aSize.width()); }
QQPoint::QQPoint(const int aX, const int aY) : QPoint(aX, aY) {;}
