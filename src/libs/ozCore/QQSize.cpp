#include "QQSize.h"

#include "Debug.h"
#include "Rational.h"

QQSize::QQSize(const QQSize aBaseSize, const QQSize aFitSize)
{
    const QQSize cMinSize = aBaseSize.min(aFitSize);
    const Rational cAspect = aBaseSize.aspect();
    if (aFitSize.isWider())
        set(aFitSize.width(), cAspect.scaled(aBaseSize.height()));
    else
        set(aBaseSize.width() * cAspect, aFitSize.height());
    TRACE << *this << aBaseSize << aFitSize << cMinSize << cAspect;
}

int QQSize::area() const
{
    return isValid() ? (width() * height()) : -1;
}

int QQSize::max() const
{
    return qMax(width(), height());
}

int QQSize::min() const
{
    return qMin(width(), height());
}

QQSize QQSize::max(const QQSize other) const
{
    QQSize result;
    if (isValid() && other.isValid())
    {
        result.width( qMax(width(),  other.width()));
        result.height(qMax(height(), other.height()));
    }
    return result;
}

QQSize QQSize::min(const QQSize other) const
{
    QQSize result;
    if (isValid() && other.isValid())
    {
        result.width( qMin(width(),  other.width()));
        result.height(qMin(height(), other.height()));
    }
    return result;
}

Rational QQSize::aspect() const
{
    return Rational(width(), height());
}

Rational QQSize::scaleOf(const QQSize other) const
{
    return Rational(other.area(), area());
}

QQSize QQSize::square() const
{
    const int cArea = area();
    const int cDim = qRound(sqrtf(float(cArea)));
    return QQSize(cDim);
}

bool QQSize::isSquare() const
{
    return width() == height();
}

bool QQSize::isWider() const
{
    return width() > height();
}

bool QQSize::isTaller() const
{
    return height() > width();
}

bool QQSize::equals(const QQSize rhs) const
{
    return width() == rhs.width()
           && height() == rhs.height();
}

QQSize QQSize::divided(const QQSize dividend) const
{
    return QQSize(width()  / dividend.width(),
                  height() / dividend.height());
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

QQSize QQSize::add(const int aInt)
{
    width(aInt + width()), height(aInt + height());
    return *this;
}

QQSize QQSize::set(const int aWidth, const int aHeight)
{
    setWidth(aWidth), setHeight(aHeight);
    return *this;
}

QQSize QQSize::set(const int aWidth, const Rational aAspect)
{
    setWidth(aWidth);
    Rational tHeight = aAspect.multiplied(aWidth);
    setHeight(tHeight.toInt());
    return *this;
}

QQSize QQSize::set(const Rational aAspect, const int aHeight)
{
    setHeight(aHeight);
    Rational tWidth = aAspect.multiplied(aHeight);
    setWidth(tWidth.toInt());
    return *this;
}
