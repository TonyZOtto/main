#pragma once
#include "ozCore.h"

#include <QList>
#include <QHash>
#include <QSet>

#include "Key.h"
#include "Value.h"

class OZCORE_EXPORT Variable
{
public: // types
    typedef QHash<Key, Variable> Hash;
    typedef QList<Variable> List;
    typedef QSet<Variable> Set;

public: // ctor
    Variable();
    Variable(const Key &k);
    Variable(const Key &k, const Value &d);
    Variable(const Key &k, const Value &c, const Value &d);

public: // const
    Key key() const;
    Value value() const;
    Value current() const;
    Value defalt() const;
    bool isNull() const;

public: // non-const
    void key(const Key &k);
    void current(const Value &c);
    void defalt(const Value &d);
    void set(const Key &k, const Value &d);
    void set(const Key &k, const Value &c, const Value &d);


private:
    Key mKey;
    Value mCurrent;
    Value mDefalt;
};

inline Key Variable::key() const { return mKey; }
inline Value Variable::current() const { return mCurrent; }
inline Value Variable::defalt() const { return mDefalt; }
inline void Variable::key(const Key &k) { mKey = k; }
inline void Variable::current(const Value &c) { mCurrent = c; }
inline void Variable::defalt(const Value &d) { mDefalt = d; }
