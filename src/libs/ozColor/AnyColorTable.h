#pragma once
#include "ozColor.h"

#include <Types.h>

#include "AnyColor.h"

class OZCOLOR_EXPORT AnyColorTable
{
public:
    AnyColorTable();
    AnyColorTable(const Count aCount);
    AnyColorTable(const QString &aString);

public: // const
    Count count() const;
    bool isValidIndex(const Index ix) const;
    AnyColor color(const Index ix) const;
    AnyColor::List list() const;

public: // non-const
    void clear(const Count size=0);
    void color(const Index ix, const AnyColor &aColor);
    void set(const QString &aString);

private:
    AnyColor::List mAnyColorList;
};

inline AnyColor::List AnyColorTable::list() const { return mAnyColorList; }

