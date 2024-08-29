#pragma once
#include "ozCore.h"

#include <QChar>
#include <QList>
#include <QString>

#include "AText.h"
#include "KeySeg.h"

class OZCORE_EXPORT Key
{
public: // types
    typedef QList<Key> List;

public: // ctors
    Key() {;}
    Key(const char * pch) { set(pch); }
    Key(const AText &atx) { set(atx); }
    Key(const QString &qs) { set(qs); }
    Key(const KeySeg::List &segs) : mSegments(segs) {;}

public: // const
    bool isNull() const;
    bool notNull() const { return ! isNull(); }
    bool startsWith(const Key &other) const;
    Count count() const;
    KeySeg seg(const Index ix) const;
    KeySeg last() const;
    KeySeg::List last(const Count aCount) const;
    Key prepended(const Key &groupKey) const;
    Key prepended(const KeySeg &seg) const;
    QString toString() const;
    operator QString() const { return toString(); }
    QString operator () () const { return toString(); }
    bool operator == (const Key &rhs) const;
    bool operator < (const Key &rhs) const;

public: // non-const
    void set(const char * pch);
    void set(const AText &atx);
    void set(const QString &qs);
    void clear();
    Key append(const Key &aKey);
    Key removeTail(const Key &aKey);

private: // static
    static KeySeg::List split(const AText &atx, const QChar hinge=QChar('/'));
    static AText joinAText(const KeySeg::List &segs, const QChar hinge=QChar('/'));
    static QString joinString(const KeySeg::List &aSegs, const QChar hinge=QChar('/'));

private:
    KeySeg::List mSegments;
};

