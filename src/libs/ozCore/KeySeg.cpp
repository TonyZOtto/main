#include "KeySeg.h"

KeySeg::KeySeg() {}

void KeySeg::set(const AText &atx)
{
    AText tInText = atx;
    AText tOutText(validFirstChar(tInText.takeFirstChar()));
    while ( ! tInText.isEmpty())
        tOutText.append(validFirstChar(tInText.takeFirstChar()));
}
