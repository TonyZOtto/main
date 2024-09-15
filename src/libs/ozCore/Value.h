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
    Value(const Qt::Orientations qtos);

public: // const
    QQSize size() const;
    int signedint() const;
    QColor color() const;
    Qt::Orientations orientations() const;
    operator QQSize () const { return size(); }
    operator int () const { return signedint(); }
    operator QColor () const { return color(); }
    operator Qt::Orientations () const { return orientations(); }


public: // non-const
    void set(const QVariant other);

private:
    QString mStringValue;
};
