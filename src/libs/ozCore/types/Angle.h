#pragma once
#include "ozCore.h"

#include "Rational.h"

class OZCORE_EXPORT Angle
{
public:
    Angle() { nullify(); }
    Angle(const int deg) { set(deg); }
    Angle(const qreal rad) { set(rad); }

public: // const
    signed int degrees() const;
    qreal degreesF() const;
    qreal radians() const;

public: // non-const
    void nullify();
    void set(const int deg);
    void set(const qreal rad);
    void setDegreesF(const qreal degf);

private:
    Rational mRational;
};
