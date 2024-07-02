#include "Key.h"

QString Key::toString() const
{
    return joinString(mSegments);
}

bool Key::operator <(const Key &rhs) const
{
    return toString() < rhs.toString();
}

KeySeg::List Key::split(const AText &atx, const QChar hinge)
{
    KeySeg::List result;
    AText::List tAtxs = atx.split(hinge.cell());
    foreach (AText tAtx, tAtxs)
        result.append(KeySeg(tAtx));
    return result;
}

void Key::set(const char *pch)

{
    mSegments = split(AText(pch));
}

void Key::set(const AText &atx)
{
    mSegments = split(atx);
}

void Key::set(const QString &qs)
{
    mSegments = split(AText(qs));
}

// static
QString Key::joinString(const KeySeg::List &aSegs, const QChar aHingeChar)
{
    KeySeg::List tSegs = aSegs;
    QString result = tSegs.takeFirst();
    while ( ! tSegs.isEmpty())
    {
        result.append(aHingeChar);
        result.append(tSegs.takeFirst());
    }
    return result;
}

