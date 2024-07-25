#include "SettingsItem.h"

#include <Key.h>

class SettingsItemData : public QSharedData
{
public:
    SettingsItem::Flags     dFlags;
    Key                     dKey;
    QVariant                dCurrentValue;
    QVariant                dDefaltValue;
    QVariant                dPreviousValue;

};

SettingsItem::SettingsItem()
    : data(new SettingsItemData)
{}

SettingsItem::SettingsItem(const SettingsItem &rhs)
    : data{rhs.data}
{}

SettingsItem &SettingsItem::operator=(const SettingsItem &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

SettingsItem::~SettingsItem() {}
