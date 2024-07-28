#include "Uid.h"

#include <MillisecondTime.h>

QRandomGenerator64 Uid::smRandom64(quint32(MillisecondTime::current()));

Uid::Uid() {;}

Uid::Uid(const bool init)
{
    if (init)
    {
        set(smRandom64(), smRandom64());
        variant(Variant7), version(QUuid::Random);
    }
//    qDebug() << Q_FUNC_INFO << init << mUuid.toByteArray();
}

bool Uid::isNull() const
{
    return mUuid.isNull();
}

Uid::operator QUuid() const
{
    return mUuid;
}

AText Uid::tail() const
{
    return mUuid.toByteArray().right(14);
}

void Uid::set(const QWORD aHi64, const QWORD aLo64)
{
    Union tUnion;
    tUnion.hi = aHi64, tUnion.lo = aLo64;
    set(tUnion);
}

void Uid::set(const OWORD ow)
{
    mUuid = QUuid::fromUInt128(ow);
}

void Uid::set(const Union u)
{
    mUuid = QUuid::fromUInt128(u.u128);
}

void Uid::set(const QQBitArray bta)
{
    set(bta.toOWord());
}

void Uid::variant(const QUuid::Variant aVariant)
{
#if 1
    QByteArray tDebugBA = mUuid.toByteArray();
    Union tUnion;
    tUnion.u128 = mUuid.toUInt128();
    WORD tW8 = tUnion.w8;
    tW8 &= 0b1111111100011111;
    tW8 |= (((WORD)aVariant) & 0b0000000000000111) << 5;
    tUnion.w8 = tW8;
    mUuid = QUuid::fromUInt128(tUnion.u128);
//    qDebug() << Q_FUNC_INFO << tDebugBA << aVariant << mUuid.toByteArray();
#else
    const QQBitArray cXBitMask = variantMask().toggled();
    QQBitArray tValueBits(BitCount);
    QQBitArray tUidBits(toOWord());
    tValueBits.set(variantBitOffset(), variantBitCount(), unsigned(v));
    tUidBits &= cXBitMask;
    tUidBits |= tValueBits;
    set(tUidBits);
#endif
}

void Uid::version(const QUuid::Version aVersion)
{
#if 1
    QByteArray tDebugBA = mUuid.toByteArray();
    Union tUnion;
    tUnion.u128 = mUuid.toUInt128();
    WORD tW6 = tUnion.w6;
    tW6 &= 0b1111111100001111;
    tW6 |= (((WORD)aVersion) & 0b0000000000001111) << 4;
    tUnion.w6 = tW6;
    mUuid = QUuid::fromUInt128(tUnion.u128);
//    qDebug() << Q_FUNC_INFO << tDebugBA << aVersion << mUuid.toByteArray();
#else
    const QQBitArray cXBitMask = versionMask().toggled();
    QQBitArray tValueBits(BitCount);
    QQBitArray tUidBits(toOWord());
    tValueBits.set(versionBitOffset(), versionBitCount(), unsigned(v));
    tUidBits &= cXBitMask;
    tUidBits |= tValueBits;
    set(tUidBits);
#endif
}

Uid::Union Uid::toUnion() const
{
    Uid::Union result;
    result.u128 = toOWord();
    return result;
}

QQBitArray Uid::variantMask()
{
    static QQBitArray sBitArray;
    if (sBitArray.isNull())
    {
        sBitArray.fill(false, BitCount);
        sBitArray.set(variantBitOffset(), variantBitCount());
    }
    return sBitArray;
}

QQBitArray Uid::versionMask()
{
    static QQBitArray sBitArray;
    if (sBitArray.isNull())
    {
        sBitArray.fill(false, BitCount);
        sBitArray.set(versionBitOffset(), versionBitCount());
    }
    return sBitArray;
}

OWORD Uid::toOWord() const
{
    return mUuid.toUInt128();
}

QQBitArray Uid::toBitArray() const
{
    return QQBitArray();
}

Uid::TypeClass Uid::typeClass() const
{
    Uid::TypeClass result = $nullTypeClass;
    const Union cUnion = toUnion();
    const WORD cW6 = cUnion.w6;
    result = Uid::TypeClass(cW6 & 0x0FFF);
    return result;
}

void Uid::typeClass(const TypeClass t)
{
    Union tUnion = toUnion();
    tUnion.w6 = (tUnion.w6 & 0xF000) | (t & 0x0FFF);
    set(tUnion);
}

bool Uid::operator <(const Uid &rhs) const
{
    return toOWord() < rhs.toOWord();
}

bool Uid::operator ==(const Uid &rhs) const
{
    return toOWord() == rhs.toOWord();
}
