#pragma once
#include "ozCore.h"

#include <QMap>
#include <QString>

#include "Ident.h"
#include "Key.h"
#include "Types.h"
#include "Uid.h"

class OZCORE_EXPORT IdentMap
{
public: // ctors
    IdentMap();

public: // const
    bool contains(const Id i) const;
    bool contains(const Key &k) const;
    bool contains(const Uid u) const;
    Ident get(const Id i) const;
    Ident get(const Key &k) const;
    Ident get(const Uid u) const;
    QString desc(const Uid u) const;
    Id id(const Uid u) const;
    Key key(const Uid u) const;
    QVariant value(const Uid u) const;

public: // non-const
    Uid add(const Uid::Type uk, const Key &k, const Id i=0, const QString &d=QString());
    void add(const Uid u, const Key &k, const Id i=0, const QString &d=QString());
    void remove(const Uid u);

private:
    QMap<Id, Uid> mIdUidMap;
    QMap<Key, Uid> mKeyUidMap;
    QMap<Uid, Ident> mUidIdentMap;
    QMap<Uid, QVariant> mUidValueMap;
};
