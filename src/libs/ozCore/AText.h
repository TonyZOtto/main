//!file {ozCode}/src/libs/ozBase/AText.h ASCII Text
#pragma once
#include "ozCore.h"

#include <QByteArray>
#include <QByteArrayList>
#include <QString>

class OZCORE_EXPORT AText : public QByteArray
{
public: // types
    typedef QByteArrayList List;

public: // ctors
    AText() {;}
    AText(const QByteArray &ba) : QByteArray(ba) {;}
    AText(const QString &s) : QByteArray(s.toLocal8Bit()) {;}
    AText(const char * pch) : QByteArray(pch) {;}
    AText(const char ch) : QByteArray(1, ch) {;}

public: // const
    QString toString() const;
    operator QString () const { return toString(); }

public: // non-const
    char takeFirstChar();

public: // static
    static QStringList toStringList(const AText::List atl);
};
