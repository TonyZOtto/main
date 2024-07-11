#include "BrightnessContrast.h"

BrightnessContrast::BrightnessContrast(const bool makeFlat)
    : mBrightness(makeFlat ? 0.0 : qQNaN())
    , mContrast(  makeFlat ? 1.0 : qQNaN()) {;}
BrightnessContrast::BrightnessContrast(const qreal aBri, const qreal aCont)
    : mBrightness(aBri), mContrast(aCont) {;}

DWORD BrightnessContrast::translate(const DWORD aInput) const
{
    DWORD result;
    qreal tFloat = (qreal(aInput) / qreal(INT16_MAX)) * contrast() + brightness();
    tFloat = qBound(0.0, tFloat, qreal(INT16_MAX - 1) / qreal(INT16_MAX));
    result = qRound(tFloat * INT16_MAX);
    return result;
}

void BrightnessContrast::set(const qreal aBri, const qreal aCont)
{
    mBrightness = aBri, mContrast = aCont;
}

void BrightnessContrast::set(const BYTE aLo, const BYTE aHi, const Count aOf)
{
    const qreal cBri = (aOf / 2) - (aLo + aHi);
    const qreal cCont = qreal(aOf) / qreal(aHi - aLo + 1);
    set(cBri, cCont);
}
