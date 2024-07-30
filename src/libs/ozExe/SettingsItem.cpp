#include "SettingsItem.h"

#include <Key.h>
#include <Success.h>

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

Key SettingsItem::key() const
{
    return data->dKey;
}

QVariant SettingsItem::value() const
{
    return currentValue().isNull()
         ? data->dDefaltValue
         : data->dCurrentValue;
}

QVariant SettingsItem::currentValue() const
{
    return data->dCurrentValue;
}

QVariant SettingsItem::defaltValue() const
{
    return data->dDefaltValue;
}

QVariant SettingsItem::previousValue() const
{
    return data->dPreviousValue;
}

SettingsItem::Flags SettingsItem::flags() const
{
    return data->dFlags;
}

bool SettingsItem::operator ==(const SettingsItem rhs) const
{
    return currentValue() == rhs.currentValue();
}

void SettingsItem::key(const Key &newKey)
{
    data->dKey = newKey;
}

void SettingsItem::currentValue(const QVariant &newValue)
{
    data->dCurrentValue = newValue;
}

void SettingsItem::previousValue(const QVariant &newValue)
{
    data->dPreviousValue = newValue;
}

void SettingsItem::defaltValue(const QVariant &defValue)
{
    data->dDefaltValue = defValue;
}

void SettingsItem::flags(const Flags aFlags)
{
    data->dFlags = aFlags;
}

SettingsItem::Flags &SettingsItem::flags()
{
    return data->dFlags;
}

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

