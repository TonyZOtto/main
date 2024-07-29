#include "SettingsItem.h"

#include <Key.h>

class OZEXE_EXPORT SettingsItemData : public QSharedData
{
public:
    Key                     dKey;
    SettingsItem::Flags     dFlags;
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
