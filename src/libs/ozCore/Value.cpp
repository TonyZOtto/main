#include "Value.h"

#include <QByteArray>
#include <QTextStream>

Value::Value() {;}
Value::Value(const QVariant other) : QVariant(other) {;}
Value::Value(const QQSize sz) : QVariant(sz) {;}

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

void Value::set(const QVariant other)
{
    *this = other;
    mStringValue = toString();
}
