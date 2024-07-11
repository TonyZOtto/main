#pragma once
#include "ozColor.h"

#include <Types.h>

class OZCOLOR_EXPORT BrightnessContrast
{
public: // ctors
    BrightnessContrast(const bool makeFlat=false);
    BrightnessContrast(const qreal aBri, const qreal aCont);

public: // const
    qreal brightness() const;
    qreal contrast() const;
    DWORD translate(const DWORD aInput) const;

public: // non-const
    void brightness(const qreal aBri);
    void contrast(const qreal aCont);
    void set(const qreal aBri, const qreal aCont);
    void set(const BYTE aLo, const BYTE aHi, const Count aOf=256);

private:
    qreal mBrightness;
    qreal mContrast;
};

inline qreal BrightnessContrast::brightness() const { return mBrightness; }
inline qreal BrightnessContrast::contrast() const { return mContrast; }
inline void BrightnessContrast::brightness(const qreal aBri) { mBrightness = aBri; }
inline void BrightnessContrast::contrast(const qreal aCont) { mContrast = aCont; }
