//!file {ozCode}/src/libs/ozBase/AText.h ASCII Text
#pragma once
#include "ozCore.h"

#include <QByteArray>
#include <QByteArrayList>
#include <QString>

#include "Types.h"

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
    AText(const Count k, const char ch) : QByteArray(k, ch) {;}

public: // const
    QString toString() const;
    operator QString () const { return toString(); }

public: // non-const
    char takeFirstChar();
    void set(const AText aText);
    void setRight(const AText &aText);
    void setUpper();

public: // static
    static QStringList toStringList(const AText::List atl);
};
