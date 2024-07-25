#pragma once

#include <QSharedDataPointer>


class SettingsItemData;

class SettingsItem
{
public: // types
    enum Flag
    {
        $null           = 0,
        Dirty           = 0x00000001,
        Changed         = 0x00000010,
        Updated         = 0x00000100,
    };
    Q_DECLARE_FLAGS(Flags, Flag)

public: // built in
    SettingsItem();
    SettingsItem(const SettingsItem &);
    SettingsItem &operator=(const SettingsItem &);
    ~SettingsItem();

public: // const

public: // non-const

public: // pointers

private:
    QSharedDataPointer<SettingsItemData> data;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(SettingsItem::Flags)
