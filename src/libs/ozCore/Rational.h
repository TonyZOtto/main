#pragma once
#include "ozCore.h"

class OZCORE_EXPORT Rational
{
public:
    typedef signed Term;
public:
    Rational();
    Rational(const Term num, const Term den);
    Rational(const qreal f, const signed den=1000000);

public: // const
    Term n() const;
    Term d() const;
    bool isNull() const;
    bool notNull() const { return ! isNull(); }
    bool isValid() const;
    bool notValid() const { return ! isValid(); }
    signed ratio() const;
    Rational flipped() const;
    qreal toReal() const;
    operator qreal () const { return toReal(); }

public: // non-const
    void n(const Term num);
    void d(const Term den);
    void set(const Term num, const Term den);
    void adjustDenominator(const Term den);
    void normalize();
    void nullify();
    void add(const Rational rat);
    void operator + (const Rational rat) { add(rat); }

private:
    Term  mNumerator;
    Term  mDenominator;
};

inline Rational::Term Rational::n() const
{
    return mNumerator;
}

inline Rational::Term Rational::d() const
{
    return mDenominator;
}

inline void Rational::n(const Term num)
{
    mNumerator = num;
}

inline void Rational::d(const Term den)
{
    mDenominator = den;
}
