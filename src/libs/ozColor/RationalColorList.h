#pragma once
#include "ozColor.h"

#include <QList>

#include <Rational.h>
#include <RationalList.h>
#include <Types.h>

#include "Color.h"

class OZCOLOR_EXPORT RationalColorList
{


public: // ctors
    RationalColorList();
    RationalColorList(const Count max);

public: // const
    Rational::Term n(const Color::Component cc) const;
    Rational::Term d() const;
    Rational get(const Color::Component cc) const;

public: // non-const
    void set(const Index ix, const WORDF wfv);

private:

private:
    RationalList mRationalList;
};

inline Rational::Term RationalColorList::n(const Color::Component cc) const { return mRationalList.n(cc); }
inline Rational::Term RationalColorList::d() const { return mRationalList.d(); }
inline Rational RationalColorList::get(const Color::Component cc) const { return mRationalList.get(cc); }
