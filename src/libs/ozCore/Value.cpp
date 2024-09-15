#include "Value.h"

#include <QByteArray>
#include <QTextStream>

#include <climits>

Value::Value() {;}
Value::Value(const QVariant other) : QVariant(other) {;}
Value::Value(const QQSize sz) : QVariant(sz) {;}
Value::Value(const int si) : QVariant(si) {;}
Value::Value(const QColor c) : QVariant(c) {;}
Value::Value(const Qt::Orientations qtos) : QVariant(qtos) {;}

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

Qt::Orientations Value::orientations() const
{
    Qt::Orientations result = Qt::Orientations(0);
    if (canConvert<Qt::Orientations>())
    {
        result = value<Qt::Orientations>();
    }
    else
    {
        const QByteArray cBA = toByteArray();
        if (cBA.contains("Horiz"))  result.setFlag(Qt::Horizontal);
        if (cBA.contains("Vert"))   result.setFlag(Qt::Vertical);
    }
    return result;
}

void Value::set(const QVariant other)
{
    *this = other;
    mStringValue = toString();
}
