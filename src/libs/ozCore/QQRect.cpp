#include "QQRect.h"

QQRect::QQRect() {}
QQRect::QQRect(const QQSize aSize) : QRect(QPoint(0,0), aSize) {;}
QQRect::QQRect(const QQPoint aTLPt, const QQSize aSize)
    : QRect(aTLPt, aSize) {;}

void QQRect::set(const QQPoint aTLPt, const QQSize aSize)
{
    QRect::setTopLeft(aTLPt), QRect::setSize(aSize);
}
