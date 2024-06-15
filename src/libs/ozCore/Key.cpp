#include "Key.h"

KeySeg::List Key::split(const AText &atx, const QChar hinge)
{
    KeySeg::List result;
    AText::List tAtxs = atx.split(hinge.cell());
    foreach (AText tAtx, tAtxs)
        result.append(KeySeg(tAtx));
    return result;
}
