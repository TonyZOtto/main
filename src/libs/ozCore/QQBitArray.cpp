#include "QQBitArray.h"

QQBitArray::QQBitArray() {}
QQBitArray::QQBitArray(const Count n, const bool fill) : QBitArray(n, fill) {;}
QQBitArray::QQBitArray(const OWORD ow) : QBitArray(QBitArray::fromBits((const char *)(&ow), sizeof(ow))) {;}

QQBitArray QQBitArray::toggled() const
{
    QQBitArray result(*this);
    result.toggle();
    return result;
}

OWORD QQBitArray::toOWord() const
{
    OWORD result = 0;
    QQBitArray tBitArray(*this);
    tBitArray.resize(sizeof(OWORD) * 8);
    memcpy(&result, tBitArray.bits(), sizeof(OWORD));
    return result;
}

void QQBitArray::set(const Index start, const Count n, const bool b)
{
    for (Index ix = start + n; ix >= start; --ix)
        setBit(ix, b);
}

void QQBitArray::set(const Index start, const Count n, unsigned int u)
{
    for (Index ix = start + n; ix >= start; --ix)
    {
        setBit(u & 1, ix);
        u >>= 1;
    }
}

void QQBitArray::toggle()
{
    for (Index ix = 0; ix < count(); ++ix)
        toggleBit(ix);
}

