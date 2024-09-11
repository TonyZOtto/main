#include "VariableSet.h"

VariableSet::VariableSet(const Ident id) : mIdent(id) {;}
VariableSet::VariableSet(const Variable::List &vl, const Ident id)
    : mIdent(id) { set(vl); }

Value VariableSet::current(const Key &k) const
{
    return get(k).current();
}

Value VariableSet::defalt(const Key &k) const
{
    return get(k).defalt();
}

bool VariableSet::contains(const Key &k) const
{
    return mHash.contains(k);
}

bool VariableSet::isNull(const Key &k) const
{
    return notContains(k) || get(k).isNull();
}

bool VariableSet::isEmpty() const
{
    return mHash.isEmpty();
}

void VariableSet::set(const Variable &v)
{
    mHash.insert(v.key(), v);
}

void VariableSet::set(const Variable::List &vl)
{
    foreach (const Variable &cVar, vl)
        set(cVar);
}

