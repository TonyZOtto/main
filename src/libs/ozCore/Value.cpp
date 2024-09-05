#include "Value.h"

Value::Value() {;}
Value::Value(const QVariant other) { set(other); }

QQSize Value::size() const
{
    QQSize result;
    if (canConvert<QSize>()) result = QQSize(toSize());
    if (canConvert<int>()) result = QQSize(toInt());
    // TODO conver from string
    return result;
}

void Value::set(const QVariant other)
{
    *this = other;
    mStringValue = toString();
}
