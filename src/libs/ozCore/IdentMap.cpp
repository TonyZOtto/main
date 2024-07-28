#include "IdentMap.h"

IdentMap::IdentMap() {}

bool IdentMap::contains(const Id i) const
{
    return mIdUidMap.contains(i);
}

bool IdentMap::contains(const Key &k) const
{
    return mKeyUidMap.contains(k);
}

bool IdentMap::contains(const Uid u) const
{
    return mUidIdentMap.contains(u);
}

Ident IdentMap::get(const Id i) const
{
    const Uid cUid = mIdUidMap.value(i);
    return mUidIdentMap.value(cUid);
}

Ident IdentMap::get(const Key &k) const
{
    const Uid cUid = mKeyUidMap.value(k);
    return mUidIdentMap.value(cUid);
}

Ident IdentMap::get(const Uid u) const
{
    return mUidIdentMap.value(u);
}

QString IdentMap::desc(const Uid u) const
{
    return get(u).desc();
}

Id IdentMap::id(const Uid u) const
{
    return get(u).id();
}

Key IdentMap::key(const Uid u) const
{
    return get(u).key();
}

Uid IdentMap::add(const Uid::Type uk, const Key &k, const Id i, const QString &d)
{
    const Uid result = Uid(uk);
    add(result, k, i, d);
    return result;
}

void IdentMap::add(const Uid u, const Key &k, const Id i, const QString &d)
{
    const Ident cIdent(u, k, i, d);
    if (i) mIdUidMap.insert(i, u);
    if (k.notNull()) mKeyUidMap.insert(k, u);
    mUidIdentMap.insert(u, cIdent);
}

void IdentMap::remove(const Uid u)
{
    if (contains(u))
    {
        Ident cIdent = get(u);
        if (contains(cIdent.id())) mIdUidMap.remove(cIdent.id());
        if (contains(cIdent.key())) mKeyUidMap.remove(cIdent.key());
        mUidIdentMap.remove(u);
    }
}
