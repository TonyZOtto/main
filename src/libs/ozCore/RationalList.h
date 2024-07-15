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
    RationalList(const Count nCount,
                 const Term aDen=65536);

public: // const
    bool isEmpty() const;
    bool isValid() const;
    Count count() const { return mNumeratorList.count(); }
    Rational at(const Index ix) const;
    List n() const;
    Rational n(const Index ix) const;
    Term d() const;

public: // non-const
    Rational at(const Index ix);
    Rational & r(const Index ix);
    void n(const Index ix, const Term num);
    void n(const List aNumList);
    void d(const Term aDen);
    void adjustDenominator(const Term den);
    void adjustDenominator(const Index ix, const Term den);
    void clear();

private:
    bool isValidIndex(const Index ix) const { return ix >= 0 && ix < Index(count()); }

private:
    List mNumeratorList;
    Term mDenominator;
};

inline RationalList::List RationalList::n() const { return mNumeratorList; }
inline RationalList::Term RationalList::d() const { return mDenominator; }
inline void RationalList::n(const List aNumList) { mNumeratorList = aNumList; }
