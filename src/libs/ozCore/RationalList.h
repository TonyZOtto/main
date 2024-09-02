#pragma once
#include "ozCore.h"

#include <QList>
#include <Rational.h>

#include <Types.h>


class OZCORE_EXPORT RationalList
{
public: // types
    typedef Rational::Term Term;
    typedef QList<Term> List;

public: // ctors
    RationalList();
    RationalList(const Count nCount, const Term aDen=0);

public: // const
    bool isEmpty() const;
    bool isValid() const;
    Count count() const { return mNumeratorList.count(); }
    Rational get(const Index ix) const;
    BYTE byte(const Index ix) const;
    List rats() const;
    Rational rat(const Index ix) const;
    Term n(const Index ix) const;
    Term d() const;

public: // non-const
    Rational get(const Index ix);
    Rational & r(const Index ix);
    void set(const Index ix, const WORDF wfv);
    void rats(const Index ix, const Term num);
    void rats(const List aNumList);
    void d(const Term aDen);
    void adjustDenominator(const Term den);
    void adjustDenominator(const Index ix, const Term den);
    void clear();

private:
    bool isValidIndex(const Index ix) const;

private:
    List mNumeratorList;
    Term mDenominator;
};

inline RationalList::List RationalList::rats() const { return mNumeratorList; }
inline RationalList::Term RationalList::n(const Index ix) const { return isValidIndex(ix) ? mNumeratorList.value(ix) : Rational::invalidTerm(); }
inline RationalList::Term RationalList::d() const { return mDenominator; }
inline void RationalList::rats(const List aNumList) { mNumeratorList = aNumList; }
