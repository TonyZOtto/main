#pragma once
#include "ozCore.h"

#include "AText.h"

#include <QChar>
#include <QList>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QString>

#include "Types.h"

class OZCORE_EXPORT KeySeg : public AText
{
public: // types
    typedef QList<KeySeg> List;

public: // ctors
    explicit KeySeg();
    KeySeg(const char * pch) { set(pch); }
    KeySeg(const AText &atx) { set(atx); }
    KeySeg(const QString &qs) { set(qs); }

public: // const
    Id toId() const;
    QString sortable() const;
    QString toString() const;
    operator QString () const { return toString(); }
    QString operator () () const { return toString(); }
    bool operator == (const KeySeg &rhs);
    bool operator <  (const KeySeg &rhs);

public: // non-const
    void set(const char * pch);
    void set(const AText &atx);
    void set(const QString &qs);

private: // static
    static char validFirstChar(const char ch);
    static char validNextChar(const char ch);
};










