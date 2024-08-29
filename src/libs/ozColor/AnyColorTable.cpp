#include "AnyColorTable.h"

#include <QColor>

AnyColorTable::AnyColorTable() {;}
AnyColorTable::AnyColorTable(const Count size) : mAnyColorList(size) {;}
AnyColorTable::AnyColorTable(const QString &aString) { set(aString); }

Count AnyColorTable::count() const
{
    return mAnyColorList.count();
}

bool AnyColorTable::isValidIndex(const Index ix) const
{
    return ix >= 0 && ix < Index(count());
}

AnyColor AnyColorTable::color(const Index ix) const
{
    return isValidIndex(ix) ? mAnyColorList.value(ix) : AnyColor();
}

void AnyColorTable::clear(const Count size)
{
    mAnyColorList.clear();
    if (size) mAnyColorList = AnyColor::List(size);
}

void AnyColorTable::color(const Index ix, const AnyColor &aColor)
{
    if (isValidIndex(ix)) mAnyColorList[ix] = aColor;
}

void AnyColorTable::set(const QString &aString)
{
    const QStringList cColorNames = aString.simplified().split(' ');
    const Count cSize = cColorNames.size();
    clear(cSize);
    for (Index ix = 0; ix < Index(cSize); ++ix)
    {
        QString cColorName = cColorNames.value(ix);
        AnyColor cColor(cColorName);
        color(ix++, cColor);
    }
}

