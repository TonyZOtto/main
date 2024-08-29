#include "RationalColorList.h"

#include <Color.h>

RationalColorList::RationalColorList() {;}
RationalColorList::RationalColorList(const Count max)
    : mRationalList(max, 65536) {;}

void RationalColorList::set(const Index ix, const WORDF wfv)
{
    mRationalList.set(ix, wfv);
}
