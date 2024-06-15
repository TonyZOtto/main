#ifndef KEY_H
#define KEY_H

#include <QChar>
#include <QString>

#include "AText.h"
#include "KeySeg.h"

class Key
{
public: // ctors
    Key() {;}
    Key(const char * pch) { set(pch); }
    Key(const AText &atx) { set(atx); }
    Key(const QString &qs) { set(qs); }

public: // const

public: // non-const
    void set(const char * pch);
    void set(const AText &atx);
    void set(const QString &qs);

private: // static
//    static KeySeg::List split(const char * pch, const QChar hinge=QChar('/'));
    static KeySeg::List split(const AText &atx, const QChar hinge=QChar('/'));
//    static KeySeg::List split(const QString &qs, const QChar hinge=QChar('/'));
    static AText joinAText(const KeySeg::List &segs, const QChar hinge=QChar('/'));
    static QString joinString(const KeySeg::List &segs, const QChar hinge=QChar('/'));

private:
    KeySeg::List mSegments;
};

inline void Key::set(const char *pch)
{
    mSegments = split(AText(pch));
}

inline void Key::set(const AText &atx)
{
    mSegments = split(atx);
}

inline void Key::set(const QString &qs)
{
    mSegments = split(AText(qs));
}

#endif // KEY_H
