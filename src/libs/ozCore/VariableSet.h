#pragma once

#include "Ident.h"
#include "Variable.h"

class VariableSet
{
public: // ctors
    VariableSet(const Ident id=Ident());
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

public: // non-const
    void set(const Variable &v);
    void set(const Variable::List &vl);

private:
    Ident mIdent;
    Variable::Hash mHash;
};

inline Variable VariableSet::get(const Key &k) const { return mHash.value(k); }
inline Ident VariableSet::ident() const { return mIdent; }

