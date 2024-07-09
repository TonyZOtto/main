#pragma once
#include "ozCore.h"

#include <QSize>

class OZCORE_EXPORT QQSize : public QSize
{
public: // ctors
    QQSize() : QSize(-1, -1) {;}
    QQSize(const int aWidth, const int aHeight) : QSize(aWidth, aHeight) {;}
    QQSize(const QSize other) : QSize(other) {;}
    QQSize(const int aDim) : QSize(aDim, aDim) {;}

public: // const
    int area() const;
    bool equals(const QQSize rhs) const;
    signed factor(const QQSize rhs) const;

};
