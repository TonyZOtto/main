#pragma once
#include "ozCore.h"

#include "Rational.h"

class OZCORE_EXPORT Angle : public Rational
{
public:
    Angle() { nullify(); }
    Angle(const int deg) { set(deg); }
    Angle(const qreal rad) { set(rad); }
    Angle(const Rational rat) { set(rat); }

public: // const
    signed int degrees() const;
    qreal degreesF() const;
    qreal radians() const;

public: // non-const
    void set(const signed deg);
    void set(const qreal rad);
    void setDegreesF(const qreal degf);

private:
};

