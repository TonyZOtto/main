#pragma once
#include "ozCore.h"

#include <QMap>
#include <QVariant>

#include "Key.h"

class OZCORE_EXPORT KeyMap : public QMap<Key, QVariant>
{
public: // types
    typedef QPair<Key, QVariant> Entry;
    typedef QList<Entry> EntryList;

public: // ctors
    KeyMap();
    KeyMap(const EntryList entries);
    KeyMap(const EntryList entries, const Key groupKey);

private:
};


