#include "KeyMap.h"


KeyMap::KeyMap(const EntryList entries)
{
    foreach (const Entry cEntry, entries)
        insert(cEntry.first, cEntry.second);
}

KeyMap::KeyMap(const EntryList entries, const Key groupKey)
{
    foreach (const Entry cEntry, entries)
        insert(cEntry.first.prepended(groupKey), cEntry.second);
}

KeyMap KeyMap::group(const Key &key) const
{
    KeyMap result;
    foreach (const Key cKey, keys())
        if (cKey.startsWith(key))
            result.insert(cKey, value(cKey));
    return result;
}

void KeyMap::clear(const Key &key)
{
    replace(key, QVariant());
}

void KeyMap::replace(const Key &key, const QVariant &value)
{
    if (contains(key))
    {
        remove(key);
        insert(key, value);
    }
}
