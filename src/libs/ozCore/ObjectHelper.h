#pragma once
#include "ozCore.h"

#include <QObject>

#include <QString>
#include <QStringList>

class OZCORE_EXPORT ObjectHelper
{
public:
    ObjectHelper(const QObject * obj);

public: // const
    const QMetaObject * metaObject() const;
    const QMetaEnum metaEnum(const QString &enumName) const;
    QStringList namesOfEnums(const bool all=false) const;
    QStringList keysInEnum(const QString &enumName) const;
    bool enumIsFlags(const QString &enumName) const;
    int enumValue(const QString &enumName, const QString &key) const;
    QStringList flagKeys(const QString &enumName, int flags, const bool isSet=true) const;

private:
    const QObject * cmpObject=nullptr;
};
