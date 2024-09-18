#include "VariableSet.h"

VariableSet::VariableSet(const Ident id) : cmIdent(id) {;}
VariableSet::VariableSet(const VariableSet &other)
    : cmIdent(other.cmIdent), mHash(other.mHash) {;}
VariableSet::VariableSet(const Variable::List &vl, const Ident id)
    : cmIdent(id) { set(vl); }

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

Variable::List VariableSet::list() const
{
    return mHash.values();
}

void VariableSet::clear()
{
    mHash.clear();
}

void VariableSet::set(const Variable &var)
{
    mHash.insert(var.key(), var);
}

void VariableSet::set(const Key &k, const Value &val)
{
    Variable tVar(k);
    tVar.current(val);
    set(tVar);
}

void VariableSet::set(const Variable::List &vl)
{
    foreach (const Variable &cVar, vl)
        set(cVar);
}

void VariableSet::set(const KeyMap &map, const Key &groupKey)
{
    foreach (const Key &cKey, map.keys())
    {
        const Variable cVar(cKey.prepended(groupKey),
                            map.value(cKey));
        set(cVar);
    }
}

