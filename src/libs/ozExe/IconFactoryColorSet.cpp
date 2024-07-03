#include "IconFactoryColorSet.h"

class IconFactoryColorSetData : public QSharedData
{
public:
    QColor  d_EdgeColor;
    QColor  d_OutsideColor;
    QColor  d_ForePenColor;
    QColor  d_ForeFillColor;
    QColor  d_BackColor;
    QColor  d_AltBackColor;

};

IconFactoryColorSet::IconFactoryColorSet()
    : data(new IconFactoryColorSetData)
{}

IconFactoryColorSet::IconFactoryColorSet(const IconFactoryColorSet &rhs)
    : data{rhs.data}
{}

IconFactoryColorSet &IconFactoryColorSet::operator=(const IconFactoryColorSet &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

IconFactoryColorSet::~IconFactoryColorSet() {}
