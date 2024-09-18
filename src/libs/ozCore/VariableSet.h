#pragma once
#include "ozCore.h"

#include "Ident.h"
#include "KeyMap.h"
#include "Variable.h"

class OZCORE_EXPORT VariableSet
{
public: // ctors
    VariableSet(const Ident id=Ident());
    VariableSet(const VariableSet &other);
    VariableSet(const Variable::List &vl, const Ident id=Ident());

public: // const
    Variable get(const Key &k) const;
    Value current(const Key &k) const;
    Value defalt(const Key &k) const;
    Ident ident() const;
    bool contains(const Key &k) const;
    bool notContains(const Key &k) const { return ! contains(k); }
    bool isNull(const Key &k) const;
    bool isEmpty() const;
    Variable::List list() const;

public: // non-const
    void clear();
    void set(const Variable &var);
    void set(const Key &k, const Value &val);
    void set(const Variable::List &vl);
    void set(const KeyMap &map, const Key &groupKey=Key());

private:
    const Ident cmIdent;
    Variable::Hash mHash;
};

inline Variable VariableSet::get(const Key &k) const { return mHash.value(k); }
inline Ident VariableSet::ident() const { return cmIdent; }

