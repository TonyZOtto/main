#pragma once
#include "ozCore.h"

#include "AText.h"

#include <QChar>
#include <QList>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QString>

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
    QString toString() const;
    QString operator() () const;
    operator QString () const;

public: // non-const
    void set(const char * pch);
    void set(const AText &atx);
    void set(const QString &qs);

private: // static
    static char validFirstChar(const char ch);
    static char validNextChar(const char ch);
};

inline QString KeySeg::toString() const
{
    return QString(QByteArray::constData());
}

inline QString KeySeg::operator()() const
{
    return toString();
}

inline KeySeg::operator QString() const
{
    return toString();
}

inline void KeySeg::set(const char *pch)
{
    set(AText(pch));
}

inline void KeySeg::set(const QString &qs)
{
    set(AText(qs));
}

inline char KeySeg::validFirstChar(const char ch)
{
    char result('_');
    static const QRegularExpression scFirstCharsRE("[_ABCDEFGHIJKLMNOPQRSTUVWXYZ]",
                                                   QRegularExpression::CaseInsensitiveOption);
    const QRegularExpressionMatch cFirstREMatch = scFirstCharsRE.match(QString(ch));
    if (cFirstREMatch.isValid()) result = ch;
    return result;
}

inline char KeySeg::validNextChar(const char ch)
{
    char result('_');
    static const QRegularExpression scNextCharsRE("[_0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ]",
                                                  QRegularExpression::CaseInsensitiveOption);
    const QRegularExpressionMatch cNextREMatch = scNextCharsRE.match(QString(ch));
    if (cNextREMatch.isValid()) result = ch;
    return result;
}


