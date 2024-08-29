#include "Key.h"

bool Key::isNull() const
{
    return mSegments.isEmpty();
}

bool Key::startsWith(const Key &other) const
{
    if (count() < other.count())    return false;
    for (Seq ix = 0; ix < other.count(); ++ix)
        if (seg(ix) != other.seg(ix))   return false;
    return true;
}

Count Key::count() const
{
    return mSegments.count();
}

KeySeg Key::seg(const Index ix) const
{
    return mSegments.value(ix);
}

KeySeg Key::last() const
{
    return mSegments.last();
}

KeySeg::List Key::last(const Count aCount) const
{
    KeySeg::List result;
    Index tMidIndex = count() - aCount;
    if (tMidIndex < 0) tMidIndex = 0;
    result = mSegments.mid(tMidIndex);
    return result;
}

Key Key::prepended(const Key &groupKey) const
{
    KeySeg::List tSegs = mSegments;
    KeySeg::List tGrpK = groupKey.mSegments;
    while ( ! tGrpK.isEmpty())
        tSegs.prepend(tGrpK.takeLast());
    return tSegs;
}

Key Key::prepended(const KeySeg &seg) const
{
    KeySeg::List tSegs = mSegments;
    tSegs.prepend(seg);
    return tSegs;
}

QString Key::toString() const
{
    return joinString(mSegments);
}

bool Key::operator ==(const Key &rhs) const
{
    return mSegments == rhs.mSegments;
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

void Key::clear()
{
    mSegments.clear();
}

Key Key::append(const Key &aKey)
{
    mSegments.append(aKey.mSegments);
    return *this;
}

Key Key::removeTail(const Key &aKey)
{
    const Count cSegCount = aKey.count();
    const KeySeg::List cTail = last(cSegCount);
    if (aKey == cTail)
        mSegments.remove(count() - cSegCount, cSegCount);
    return *this;
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

