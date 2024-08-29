#pragma once
#include "ozColor.h"

#include <QList>
#include <QRgb>

class AnyColorTable;

class OZCOLOR_EXPORT Rgba32Table
{
public:
    Rgba32Table();
    Rgba32Table(const AnyColorTable &aTable);

public: // non-const
    void set(const AnyColorTable &aTable);

private:
    QList<QRgb> mRgbaList;
};
