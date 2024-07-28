#pragma once
#include "ozCore.h"

#include <QBitArray>

#include "Types.h"

class OZCORE_EXPORT QQBitArray : public QBitArray
{
public: // ctors
    QQBitArray();
    QQBitArray(const Count n, const bool fill=false);
    QQBitArray(const OWORD ow);

public: // const
    QQBitArray toggled() const;
    OWORD toOWord() const;

public: // non-const
    void set(const Index start, const Count n, const bool b=true);
    void set(const Index start, const Count n, unsigned int u);
    void toggle();
};
