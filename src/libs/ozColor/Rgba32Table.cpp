#include "Rgba32Table.h"

#include "AnyColorTable.h"

Rgba32Table::Rgba32Table() {;}
Rgba32Table::Rgba32Table(const AnyColorTable &aTable) { set(aTable); }

void Rgba32Table::set(const AnyColorTable &aTable)
{
    mRgbaList.clear();
    foreach (const AnyColor cAny, aTable.list())
    {
        const QRgb cRgba = cAny.qrgba32();
        mRgbaList.append(cRgba);
    }
}

