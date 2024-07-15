#include "RationalList.h"

RationalList::RationalList()
{
    clear();
}

RationalList::RationalList(const Count nCount, const Rational::Term aDen)
    : mDenominator(aDen)
{
    mNumeratorList.fill(0, nCount);
}

bool RationalList::isEmpty() const
{
    return mNumeratorList.isEmpty();
}

bool RationalList::isValid() const
{
    return 0 != mDenominator;
}

Rational RationalList::at(const Index ix) const
{
    return Rational(n(ix),  d());
}

Rational RationalList::n(const Index ix) const
{
    return isValidIndex(ix) ? mNumeratorList.at(ix) : INT_MIN;
}

void RationalList::clear()
{
    mNumeratorList.clear(), mDenominator = 0;
}

