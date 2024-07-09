#include "Rational.h"

Rational::Rational() : mNumerator(0), mDenominator(0) {;}
Rational::Rational(const signed int num, const signed int den)
    : mNumerator(num), mDenominator(den) {;}
Rational::Rational(const qreal f, const signed int den)
    : mNumerator(qRound(f * qreal(den))), mDenominator(den) {;}

bool Rational::isNull() const
{
    return 0 == n();
}

bool Rational::isValid() const
{
    return 0 != d();
}

signed int Rational::ratio() const
{
    if (notValid()) return INT_MIN;
    return n() / d();
}

Rational Rational::flipped() const
{
    return Rational(d(), n());
}

qreal Rational::toReal() const
{
    if (notValid()) return qQNaN();
    return qreal(n()) / qreal(d());
}

void Rational::set(const signed int num, const signed int den)
{
    n(num), d(den);
}

void Rational::adjustDenominator(const signed int den)
{
    if (isValid() && den != d())
    {
        n(qRound(toReal() * den));
        d(den);
    }
}

void Rational::normalize()
{
    if (d() < 0) n( - n()), d( - d());
}


void Rational::nullify()
{
    n(0), d(0);
}

void Rational::add(const Rational rat)
{
    if (d() == rat.d())
    {
        n(n() + rat.n());
    }
    else
    {
        signed tDen = d() * rat.d();
        signed tNum = d() * rat.n() + n() * rat.d();
        set(tNum, tDen);
    }
}
