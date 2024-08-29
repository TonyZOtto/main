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

public: // non-const
    void set(const Index ix, const WORDF wfv);

private:

private:
    RationalList mRationalList;
};
