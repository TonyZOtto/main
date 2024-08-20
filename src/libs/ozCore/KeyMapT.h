#pragma once
#include "ozCore.h"

#include <QList>
#include <QMap>
#include <QPair>
#include <QVariant>

#include "DualMap.h"
#include "Key.h"

template <typename T> class KeyMapT
{
public: // types
    typedef QPair<Key, T> Entry;
    typedef QList<Entry> EntryList;

public: // ctors
    KeyMapT() {;}
    KeyMapT(const EntryList &aEntryList) { set(aEntryList); }
    KeyMapT(const EntryList &aEntryList, const Key &aGroupKey)
        { set(aEntryList, aGroupKey); }

public: // const
    T get(const Key &aKey)
        { return mKeyTDMap.at(mCurrentGroupKey + aKey); }
    Key key(const T &aT)
        { return mKeyTDMap.at(aT); }
    Key groupKey() const { return mCurrentGroupKey; }

public: // non-const
    void set(const Key &aKey, const T &aT);
    void set(const Entry &aEntry)
        { set(aEntry.first, aEntry.second); }
    void set(const EntryList &aEntryList)
        { foreach (const Entry cEntry, aEntryList) set(cEntry); }
    void set(const EntryList &aEntryList, const Key &aGroupKey)
        { beginGroup(aGroupKey); set(aEntryList); endGroup(aGroupKey); }
    void clear() { mKeyTDMap.clear(); clearGroup(); }
    Key beginGroup(const Key &aGroupKey, const bool root=false)
        { if (root) mCurrentGroupKey.clear(); mCurrentGroupKey.append(aGroupKey); return *this; }
    Key endGroup(const Key &aGroupKey)
        { mCurrentGroupKey.removeTail(aGroupKey); return mCurrentGroupKey; }
    void clearGroup() { mCurrentGroupKey.clear(); }

private:
    DualMap<Key, T> mKeyTDMap;
    Key mCurrentGroupKey;
};


template<typename T>
inline void KeyMapT<T>::set(const Key &aKey, const T &aT)
{
    mKeyTDMap.insertUnique(mCurrentGroupKey + aKey, aT);
}


