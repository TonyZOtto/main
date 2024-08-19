#include "RationalColorList.h"

#include <Color.h>

RationalColorList::RationalColorList() { ctor(); }

void RationalColorList::ctor()
{
    if (mRationalList.isEmpty())
        mRationalList = RationalList(Color::$maxComponent, 1024);
}
