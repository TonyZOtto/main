#pragma once
#include "ozCore.h"

#include <QVariant>

#include <QColor>

#include <QQSize.h>

class OZCORE_EXPORT Value : public QVariant
{
public: // ctors
    Value();
    Value(const QVariant other);
    Value(const QQSize sz);
    Value(const int si);
    Value(const QColor c);

public: // const
    QQSize size() const;
    int signedint() const;
    QColor color() const;
    operator QQSize () const { return size(); }
    operator int () const { return signedint(); }
    operator QColor () const { return color(); }


public: // non-const
    void set(const QVariant other);

private:
    QString mStringValue;
};
