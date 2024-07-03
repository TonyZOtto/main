#pragma once

#include <QColor>
#include <QSharedDataPointer>

class IconFactoryColorSetData;

class IconFactoryColorSet
{
public:
    IconFactoryColorSet();
    IconFactoryColorSet(const IconFactoryColorSet &);
    IconFactoryColorSet &operator=(const IconFactoryColorSet &);
    ~IconFactoryColorSet();

private:
    QSharedDataPointer<IconFactoryColorSetData> data;
};
