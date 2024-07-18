#include "Rational.h"

Rational::Rational() : mNumerator(0), mDenominator(0) {;}
Rational::Rational(const Term num, const Term den)
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

Rational Rational::multiplied(const Term aNum) const
{
    Rational result(*this);
    result.n(n() * aNum);
    return result;
}

Rational Rational::divided(const Term aDen) const
{
    Rational result(*this);
    result.d(d() * aDen);
    return result;
}

Rational::Term Rational::toInt() const
{
    return isValid() ? qRound(qreal(n()) / qreal(d()))
                     : cmInvalidTerm;
}

qreal Rational::toReal() const
{
    if (notValid()) return qQNaN();
    return qreal(n()) / qreal(d());
}

void Rational::set(const Term aNum, const Term aDen)
{
    n(aNum), d(aDen);
}

void Rational::adjustDenominator(const Term aDen)
{
    if (isValid() && aDen != d())
    {
        n(qRound(toReal() * aDen));
        d(aDen);
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

void Rational::add(const Rational aRat)
{
    if (d() == aRat.d())
    {
        n(n() + aRat.n());
    }
    else
    {
        signed tDen = d() * aRat.d();
        signed tNum = d() * aRat.n() + n() * aRat.d();
        set(tNum, tDen);
    }
}
