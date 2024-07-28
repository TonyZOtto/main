#include "IdentMap.h"

IdentMap::IdentMap() {}

bool IdentMap::contains(const Id i) const
{
    return mIdIdentMap.contains(i);
}

bool IdentMap::contains(const Key &k) const
{
    return mKeyIdentMap.contains(k);
}

bool IdentMap::contains(const Uid u) const
{
    return mUidIdentMap.contains(u);
}

Ident IdentMap::get(const Id i) const
{
    return mIdIdentMap.value(i);
}

Ident IdentMap::get(const Key &k) const
{
    return mKeyIdentMap.value(k);
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
    if (i) mIdIdentMap.insert(i, cIdent);
    if (k.notNull()) mKeyIdentMap.insert(k, cIdent);
    mUidIdentMap.insert(u, cIdent);
}

void IdentMap::remove(const Uid u)
{
    if (contains(u))
    {
        Ident cIdent = get(u);
        if (contains(cIdent.id())) mIdIdentMap.remove(cIdent.id());
        if (contains(cIdent.key())) mKeyIdentMap.remove(cIdent.key());
        mUidIdentMap.remove(u);
    }
}
