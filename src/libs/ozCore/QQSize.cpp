#include "QQSize.h"

#include "Rational.h"

QQSize::QQSize(const int aWidth, const Rational aAspect)
{
    setWidth(aWidth);
    Rational tHeight = aAspect.multiplied(aWidth);
    setHeight(tHeight.toInt());
}

QQSize::QQSize(const Rational aAspect, const int aHeight)
{
    setHeight(aHeight);
    Rational tWidth = aAspect.multiplied(aHeight);
    setWidth(tWidth.toInt());
}

int QQSize::area() const
{
    return isValid() ? (width() * height()) : -1;
}

bool QQSize::equals(const QQSize rhs) const
{
    return width() == rhs.width()
           && height() == rhs.height();
}

signed int QQSize::factor(const QQSize rhs) const
{
    if (equals(rhs)) return 0;
    signed result = INT_MIN;
    Rational tWidthFactor, tHeightFactor;
    if (area() < rhs.area())
    {
        tWidthFactor.set(rhs.width(), width()),
        tHeightFactor.set(rhs.height(), height());
        result = - qMax(tWidthFactor.ratio(), tHeightFactor.ratio());
    }
    else
    {
        tWidthFactor.set(rhs.width(), width()),
        tHeightFactor.set(rhs.height(), height());
        result = qMax(tWidthFactor.ratio(), tHeightFactor.ratio());
    }
    return result;
}
