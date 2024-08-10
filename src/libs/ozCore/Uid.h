#pragma once
#include "ozCore.h"

#include <QUuid>

#include <QList>
#include <QRandomGenerator64>


#include "AText.h"
#include "QQBitArray.h"
#include "Types.h"

/*  UUID:   00112233-4455-6677-8899-aabbccddeeff
 *  BitIndex:\-0^-16 ^-32 ^-48 ^-64 ^-80^-96^-112\=128
 *  Ver 7:  018ede8a-1e00-7d81-a387-223b32bfdb16
 *  Var 4:  018ede8a-d384-73f6-8468-b29dc030df18
 *  OurBase:00112233-4455-4677-E899-aabbccddeeff
 *                             ^--Variant (3 upper bits=0b1110)
 *                        ^--Version
 *      Version 4=Random--^    ^--Variant 7=Reserved
 *          ^^^^^^^^ ^^^^--Randomness (48 bits)
 *                         ^--TypeClass (4 bits)
 *                          ^^--Reserved7 (8 bits)
 *                             1^^^-^^^^^^^^^^^^--TypeValue (61 bits)
 *
 *  Type
 *  Class:  TypeValue (61 bits-upper 3 bits of QWORD for Varaint)
 *      0   0xExxxxxxx xxxxxxxx -  0 bits TypeA, 60 bits Value
 *      1   0xEtxxxxxx xxxxxxxx -  4 bits TypeB, 56 bits Value
 *      2   0xEttxxxxx xxxxxxxx -  8 bits TypeC, 52 bits Value
 *      3   0xEtttxxxx xxxxxxxx - 12 bits TypeD, 48 bits Value
 *      4   0xEttttxxx xxxxxxxx - 16 bits TypeE, 44 bits Value
 *      5   0xEtttttxx xxxxxxxx - 20 bits TypeF, 40 bits Value
 *      6   0xEttttttx xxxxxxxx - 24 bits TypeG, 36 bits Value
 *      7   0xEttttttt xxxxxxxx - 28 bits TypeH, 32 bits Value
 *      8   0xEttttttt txxxxxxx - 32 bits TypeJ, 28 bits Value
 *      9   0xEttttttt ttxxxxxx - 36 bits TypeK, 24 bits Value
 *     10   0xEttttttt tttxxxxx - 40 bits TypeM, 20 bits Value
 *     11   0xEttttttt ttttxxxx - 44 bits TypeN, 16 bits Value
 *     12   0xEttttttt tttttxxx - 48 bits TypeP, 12 bits Value
 *     13   0xEttttttt ttttttxx - 52 bits TypeR,  8 bits Value
 *     14   0xEttttttt tttttttx - 56 bits TypeT,  4 bits Value
 *     15 - Unused
 *  16~31 - 0xF??????? ???????? - 60 more bits of classless randomness
 */

class OZCORE_EXPORT Uid
{
public: // types
    static const QUuid::Variant Variant7 = QUuid::Variant(7);
    static const Count BitCount = sizeof(OWORD) * 8U;

    typedef union
    {
        OWORD   u128;
        struct
        {
            DWORD   d0;
            WORD    w4;
            WORD    w6;
            WORD    w8;
            DWORD   dA;
            WORD    wE;
        };
        struct
        {
            QWORD   hi;
            QWORD   lo;
        };
    } Union;

    enum TypeClass
    {
        $nullTypeClass = -1,
        TypeA = 0,
        TypeB,
        TypeC,
        TypeD,
        TypeE,
        TypeF,
        TypeG,
        TypeH,
        TypeJ,
        TypeK,
        TypeM,
        TypeN,
        TypeP,
        TypeR,
        TypeT,
        TypeUnused, // =15
        TypeRandom, // =16
    };

    enum TypeClassBits  // ValueBits = 60-Class
    {
        ClassA =  0,
        ClassB =  4,
        ClassC =  8,
        ClassD = 12,
        ClassE = 16,
        ClassF = 20,
        ClassG = 24,
        ClassH = 28,
        ClassJ = 32,
        ClassK = 36,
        ClassM = 40,
        ClassN = 44,
        ClassP = 48,
        ClassR = 52,
        ClassT = 56,
    };
    enum Type
    {
        $nullType           = 0,
        CacheEntry          = TypeE | 1,
        FrameData           = TypeE | 2,
        FaceData            = TypeE | 3,
    };
    typedef QList<Uid> List;

public: // ctors
    Uid(); // null
    Uid(const bool init); // ver4 var7 random

public: // const
    bool isNull() const;
    bool notNull() const { return ! isNull(); }
    QUuid::Variant variant() const;
    QUuid::Version version() const;
    Union toUnion() const;
    OWORD toOWord() const;
    QQBitArray toBitArray() const;
    QWORD hi() const;
    QWORD lo() const;
    TypeClass typeClass() const;
    QWORD key() const;
    QWORD value() const;
    bool operator < (const Uid &rhs) const;
    bool operator == (const Uid &rhs) const;
    operator QUuid () const;
    AText tail() const;

public: // non-const
    void set(const QWORD aHi64, const QWORD aLo64);
    void set(const OWORD ow);
    void set(const Union u);
    void set(const QQBitArray bta);
    void variant(const QUuid::Variant aVariant);
    void version(const QUuid::Version aVersion);
    void hi(const QWORD qw);
    void lo(const QWORD qw);
    void type(const Type t);
    void typeClass(const TypeClass k);
    void key(const QWORD qw48);
    void value(const QWORD qw48);

private: // static
    static QRandomGenerator64 smRandom64;
    static QQBitArray variantMask();
    static QQBitArray versionMask();
    static Count variantBitCount()      { return 3; }
    static Count versionBitCount()      { return 4; }
    static Index variantBitOffset()     { return 64; }
    static Index versionBitOffset()     { return 48; }

private:
    QUuid mUuid;
};

