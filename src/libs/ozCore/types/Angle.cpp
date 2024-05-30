#include "Angle.h"


signed Angle::degrees() const
{
    Rational tRational = mRational;
    tRational.adjustDenominator(360);
    return tRational.n();
}

qreal Angle::degreesF() const
{
    Rational tRational = mRational;
    tRational.adjustDenominator(3600000000);
    return tRational.n();
}

qreal Angle::radians() const
{
    return mRational.toReal();
}

void Angle::nullify()
{
    mRational.nullify();
}

void Angle::set(const int deg)
{
    mRational.set(deg, 360);
}

void Angle::set(const qreal rad)
{
    mRational.set(rad * 200000000.0, 200000000);
}

void Angle::setDegreesF(const qreal degf)
{
    mRational.set(degf * 3600000000.0, 3600000000);
}
