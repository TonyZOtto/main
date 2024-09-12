#include "Value.h"

#include <QByteArray>
#include <QTextStream>

#include <climits>

Value::Value() {;}
Value::Value(const QVariant other) : QVariant(other) {;}
Value::Value(const QQSize sz) : QVariant(sz) {;}
Value::Value(const int si) : QVariant(si) {;}
Value::Value(const QColor c) : QVariant(c) {;}

QQSize Value::size() const
{
    QQSize result;
    if (canConvert<QSize>()) result = QQSize(toSize());
    else if (canConvert<int>()) result = QQSize(toInt());
    if (result.isEmpty())
    {
        const QByteArray cBA = toByteArray();
        QTextStream tQTS(cBA);
        int tWidth = -1, tHeight = -1;
        if ( ! tQTS.atEnd()) tQTS >> tWidth;
        if ( ! tQTS.atEnd()) tQTS >> tHeight;
        result.set(tWidth, tHeight);
    }
    return result;
}

int Value::signedint() const
{
    int result = INT_MIN;
    if (canConvert<int>()) result = toInt();
    else result = toString().toInt();
    return result;
}

QColor Value::color() const
{
    QColor result;
    if (canConvert<QColor>()) result = value<QColor>();
    else result = QColor(toString());
    return result;
}

void Value::set(const QVariant other)
{
    *this = other;
    mStringValue = toString();
}
