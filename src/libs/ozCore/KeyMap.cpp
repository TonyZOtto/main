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
