#pragma once
#include "ozCore.h"

#include <QSharedDataPointer>
#include <QVariant>

#include <Key.h>

class SettingsItemData;

class OZCORE_EXPORT SettingsItem
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
    SettingsItem(const Key &aKey);
    SettingsItem(const Key &aKey, const QVariant &aDefalt);
    SettingsItem(const Key &aKey, const QVariant &aCurrent, const QVariant &aDefalt);

public: // const
    Key key() const;
    QVariant value() const;
    QVariant currentValue() const;
    QVariant defaltValue() const;
    QVariant previousValue() const;
    Flags flags() const;
    bool operator == (const SettingsItem rhs) const;

public: // non-const
    void key(const Key &newKey);
    void currentValue(const QVariant &newValue);
    void previousValue(const QVariant &prevValue);
    void defaltValue(const QVariant &defValue);
    void flags(const Flags aFlags);
    Flags & flags();

public: // pointers

private:
    QSharedDataPointer<SettingsItemData> data;
};



Q_DECLARE_OPERATORS_FOR_FLAGS(SettingsItem::Flags)
