#pragma once
#include "ozCore.h"

#include <QVariant>

#include <QQSize.h>

class OZCORE_EXPORT Value : public QVariant
{
public: // ctors
    Value();
    Value(const QVariant other);
    Value(const QQSize sz);

public: // const
    QQSize size() const;


public: // non-const
    void set(const QVariant other);

private:
    QString mStringValue;
};
