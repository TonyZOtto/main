#pragma once
#include "ozCore.h"

class OZCORE_EXPORT Rational
{
public:
    Rational();
    Rational(const signed num, const signed den);
    Rational(const qreal f, const signed den=1000000);

public: // const
    signed n() const;
    signed d() const;
    bool isNull() const;
    bool notNull() const { return ! isNull(); }
    bool isValid() const;
    bool notValid() const { return ! isValid(); }
    qreal toReal() const;
    operator qreal () const { return toReal(); }

public: // non-const
    void n(const signed num);
    void d(const signed den);
    void set(const signed num, const signed den);
    void adjustDenominator(const signed den);
    void normalize();
    void nullify();
    void add(const Rational rat);
    void operator + (const Rational rat) { add(rat); }

private:
    signed  mNumerator;
    signed  mDenominator;
};

inline signed int Rational::n() const
{
    return mNumerator;
}

inline signed int Rational::d() const
{
    return mDenominator;
}

inline void Rational::n(const signed int num)
{
    mNumerator = num;
}

inline void Rational::d(const signed int den)
{
    mDenominator = den;
}
