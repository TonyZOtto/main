#pragma once
#include "ozCore.h"

#include <QMap>
#include <QMetaType>
#include <QVariant>

#include "Key.h"

class OZCORE_EXPORT KeyMap : public QMap<Key, QVariant>
{
public: // types
    typedef QPair<Key, QVariant> Entry;
    typedef QList<Entry> EntryList;

public: // ctors
    KeyMap(const EntryList entries);
    KeyMap(const EntryList entries, const Key groupKey);

public: // const
    KeyMap group(const Key &key) const;

public: // non-const
    void clear(const Key &key);
    void replace(const Key &key, const QVariant &value);

private:

public: // QMetaType
    KeyMap() = default;
    ~KeyMap() = default;
    KeyMap(const KeyMap &) = default;
    KeyMap &operator=(const KeyMap &) = default;
};

Q_DECLARE_METATYPE(KeyMap);

