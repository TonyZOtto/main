#include "Rational.h"

Rational::Rational() : mNumerator(0), mDenominator(0) {;}
Rational::Rational(const signed int n, const signed int d)
    : mNumerator(n), mDenominator(d) {;}
Rational::Rational(const qreal f, const signed int d)
    : mNumerator(qRound(f * qreal(d))), mDenominator(d) {;}

bool Rational::isNull() const
{
    return 0 == n();
}

bool Rational::isValid() const
{
    return 0 == d();
}

qreal Rational::toReal() const
{
    if (notValid()) return qQNaN();
    return qreal(n()) / qreal(d());
}

void Rational::set(const signed int nn, const signed int dd)
{
    n(nn), d(dd);
}

void Rational::normalize()
{
    if (d() < 0) n( - n()), d( - d());
}

