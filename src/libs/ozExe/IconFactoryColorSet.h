#pragma once
#include "ozExe.h"

#include <QColor>
#include <QSharedDataPointer>

class IconFactoryColorSetData;

class OZEXE_EXPORT IconFactoryColorSet
{
public:
    IconFactoryColorSet();
    IconFactoryColorSet(const IconFactoryColorSet &);
    IconFactoryColorSet &operator=(const IconFactoryColorSet &);
    ~IconFactoryColorSet();

private:
    QSharedDataPointer<IconFactoryColorSetData> data;
};
