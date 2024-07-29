#pragma once
#include "ozExe.h"

#include <QSharedDataPointer>
#include <QVariant>

#include <Key.h>

class SettingsItemData;

class OZEXE_EXPORT SettingsItem
{
public: // types
    enum Flag
    {
        $null           = 0,
        Dirty           = 0x00000001,
        Changed         = 0x00000010,
        Updated         = 0x00000100,
        Watch           = 0x00010000,
        WriteOnly       = 0x01000000,
    };
    Q_DECLARE_FLAGS(Flags, Flag)

public: // built in
    SettingsItem();
    SettingsItem(const SettingsItem &);
    SettingsItem &operator=(const SettingsItem &);
    ~SettingsItem();

public: // ctors
    SettingsItem(const Key &key);
    SettingsItem(const Key &key, const QVariant &defalt);
    SettingsItem(const Key &key, const QVariant &current, const QVariant &defalt);

public: // const
    QVariant value() const;

public: // non-const
    void value(const QVariant &newValue);
    void defalt(const QVariant &defValue);
    void flags(const Flags aFlags);

public: // pointers

private:
    QSharedDataPointer<SettingsItemData> data;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(SettingsItem::Flags)
