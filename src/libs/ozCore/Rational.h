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
    Rational multiplied(const Term aNum) const;
    Rational divided(const Term aDen) const;
    Term toInt() const;
    qreal toReal() const;
    operator qreal () const { return toReal(); }

public: // non-const
    void n(const Term aNum);
    void d(const Term aDen);
    void set(const Term aNum, const Term aDen);
    void adjustDenominator(const Term aDen);
    void normalize();
    void nullify();
    void add(const Rational aRat);
    void operator + (const Rational aRat) { add(aRat); }

public: // static
    static Term invalidTerm();

private:
    Term  mNumerator;
    Term  mDenominator;
    static Term smInvalidTerm;
};

inline Rational::Term Rational::n() const { return mNumerator; }
inline Rational::Term Rational::d() const { return mDenominator; }
inline Rational::Term Rational::invalidTerm() { return smInvalidTerm; }
inline void Rational::n(const Term aNum) { mNumerator = aNum; }
inline void Rational::d(const Term aDen) { mDenominator = aDen; }

