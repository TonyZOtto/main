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
    QQSize(const int aWidth, const Rational aAspect);
    QQSize(const Rational aAspect, const int aHeight);
    QQSize(const QQSize aBaseSize, const QQSize aFitSize);
    QQSize(const QSize other) : QSize(other) {;}

public: // const
    int area() const;
    bool equals(const QQSize rhs) const;
    signed factor(const QQSize rhs) const;

};
