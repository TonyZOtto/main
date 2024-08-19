#pragma once
#include "ozColor.h"

#include <QList>

#include <Rational.h>
#include <RationalList.h>

class OZCOLOR_EXPORT RationalColorList
{


public: // ctors
    RationalColorList();

public: // const

public: // non-const

private:
    void ctor();

private:
    RationalList mRationalList;
};
