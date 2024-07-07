#pragma once
#include "ozCore.h"

#include <QtGlobal>

#include "AText.h"

class OZCORE_EXPORT UInt32
{
    typedef quint32 Type;
    const qsizetype ByteSize = sizeof(Type);
    const qsizetype NibbleSize = ByteSize << 1;
    const qsizetype BitSize = ByteSize << 3;

public:
    UInt32() : mU32(__UINT32_MAX__) {;}
    UInt32(const Type aU32) : mU32(aU32) {;}

public: // const
    Type get() const { return mU32; }
    AText hex(const bool usePrefix=false) const;
    operator Type () const { return mU32; }

public: // non-const
    Type set(const Type aU32) { return mU32 = aU32; }

private:
    Type mU32;
};

