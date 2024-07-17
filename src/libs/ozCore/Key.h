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

public: // const
    KeySeg last() const;
    QString toString() const;
    operator QString() const { return toString(); }
    QString operator () () const { return toString(); }
    bool operator <(const Key &rhs) const;

public: // non-const
    void set(const char * pch);
    void set(const AText &atx);
    void set(const QString &qs);

private: // static
    static KeySeg::List split(const AText &atx, const QChar hinge=QChar('/'));
    static AText joinAText(const KeySeg::List &segs, const QChar hinge=QChar('/'));
    static QString joinString(const KeySeg::List &aSegs, const QChar hinge=QChar('/'));

private:
    KeySeg::List mSegments;
};

