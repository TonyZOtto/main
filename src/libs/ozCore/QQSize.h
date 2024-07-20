#pragma once
#include "ozCore.h"

#include <QSize>

#include "Rational.h"

class OZCORE_EXPORT QQSize : public QSize
{
public: // ctors
    QQSize() : QSize(-1, -1) {;}
    QQSize(const int aDim) : QSize(aDim, aDim) {;}
    QQSize(const int aWidth, const int aHeight) : QSize(aWidth, aHeight) {;}
    QQSize(const int aWidth, const Rational aAspect) { set(aWidth, aAspect); }
    QQSize(const Rational aAspect, const int aHeight) { set(aAspect, aHeight); }
    QQSize(const QQSize aBaseSize, const QQSize aFitSize);
    QQSize(const QSize other) : QSize(other) {;}

public: // const
    int area() const;
    int max() const;
    int min() const;
    Rational aspect() const;
    Rational scaleOf(const QQSize other) const;
    QQSize square() const;
    bool isSquare() const;
    bool isWider() const;
    bool isTaller() const;
    bool equals(const QQSize rhs) const;
    signed factor(const QQSize rhs) const;

public: // non-const
    QQSize set(const int aWidth, const int aHeight);
    QQSize set(const int aWidth, const Rational aAspect);
    QQSize set(const Rational aAspect, const int aHeight);

};
