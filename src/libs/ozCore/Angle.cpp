#include "Angle.h"


signed Angle::degrees() const
{
    Angle tAngle(Rational(*this));
    tAngle.adjustDenominator(360);
    return tAngle.n();
}

qreal Angle::degreesF() const
{
    Angle tAngle(Rational(*this));
    tAngle.adjustDenominator(36000000L);
    return tAngle.toReal();
}

qreal Angle::radians() const
{
    return toReal();
}

void Angle::set(const signed deg)
{
    Rational::set(deg, 360);
}

void Angle::set(const qreal rad)
{
    Rational::set(qRound(rad * 2000000.0), 2000000);
}

void Angle::setDegreesF(const qreal degf)
{
    Rational::set(qRound(degf * 36000000.0), 36000000);
}
