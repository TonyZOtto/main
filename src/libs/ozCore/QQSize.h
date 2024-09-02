#pragma once
#include "ozCore.h"

#include <QList>
#include <QSize>

#include "Rational.h"

class OZCORE_EXPORT QQSize : public QSize
{
public: // types
    typedef QList<QQSize> List;

public: // ctors
    QQSize() : QSize(-1, -1) {;}
    explicit QQSize(const int aDim) : QSize(aDim, aDim) {;}
    QQSize(const int aWidth, const int aHeight) : QSize(aWidth, aHeight) {;}
    QQSize(const int aWidth, const Rational aAspect) { set(aWidth, aAspect); }
    QQSize(const Rational aAspect, const int aHeight) { set(aAspect, aHeight); }
    QQSize(const QQSize aBaseSize, const QQSize aFitSize);
    QQSize(const QSize other) : QSize(other) {;}

public: // const
    int width() const;
    int height() const;
    int area() const;
    int max() const;
    int min() const;
    bool notEmpty() const { return ! isEmpty(); }
    QQSize max(const QQSize other) const;
    QQSize min(const QQSize other) const;
    Rational aspect() const;
    Rational scaleOf(const QQSize other) const;
    QQSize square() const;
    bool isSquare() const;
    bool isWider() const;
    bool isTaller() const;
    bool equals(const QQSize rhs) const;
    QQSize divided(const QQSize dividend) const;
    signed factor(const QQSize rhs) const;
    QQSize operator / (const QQSize &dividend) const { return divided(dividend); }

public: // non-const
    QQSize width(const int aWidth);
    QQSize height(const int aHeight);
    QQSize add(const int aInt);
    QQSize operator += (const int aInt) { return add(aInt); }
    QQSize set(const int aWidth, const int aHeight);
    QQSize set(const int aWidth, const Rational aAspect);
    QQSize set(const Rational aAspect, const int aHeight);
};

inline int QQSize::width() const {  return QSize::width(); }
inline int QQSize::height() const { return QSize::height(); }
inline QQSize QQSize::width(const int aWidth) { setWidth(aWidth); return *this; }
inline QQSize QQSize::height(const int aHeight) { setHeight(aHeight); return *this; }
