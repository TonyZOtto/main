#pragma once
#include "ozCore.h"

#include <QVariant>

#include <QColor>

#include <SCRect.h>
#include <QQSize.h>

class OZCORE_EXPORT Value : public QVariant
{
public: // ctors
    Value();
    Value(const QVariant other);
    Value(const QQSize sz);
    Value(const SCRect scr);
    Value(const int si);
    Value(const QColor c);
    Value(const Qt::Orientations qtos);

public: // const
    QQSize size() const;
    int signedint() const;
    QColor color() const;
    SCRect screct() const;
    Qt::Orientations orientations() const;
    QVariant operator () () const { return QVariant(*this); }
    operator QQSize () const { return size(); }
    operator SCRect () const { return screct(); }
    operator int () const { return signedint(); }
    operator QColor () const { return color(); }
    operator Qt::Orientations () const { return orientations(); }


public: // non-const
    void set(const QVariant other);

private:
    QString mStringValue;
};
