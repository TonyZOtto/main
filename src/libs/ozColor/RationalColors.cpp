#include "RationalColors.h"

#include <Color.h>

RationalColors::RationalColors() { ctor(); }

void RationalColors::ctor()
{
    if (mRationalList.isEmpty())
        mRationalList = RationalList(Color::$maxComponent, 1024);
}
