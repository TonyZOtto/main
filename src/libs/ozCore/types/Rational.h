#pragma once
#include "eIRcore.h"

class EIRCORE_EXPORT Rational
{
public:
    Rational();
    Rational(const signed n, const signed d);
    Rational(const qreal f, const signed d=1000000000);

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
    void n(const signed v);
    void d(const signed v);
    void set(const signed n, const signed d);
    void normalize();

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

inline void Rational::n(const signed int v)
{
    mNumerator = v;
}

inline void Rational::d(const signed int v)
{
    mDenominator = v;
}
