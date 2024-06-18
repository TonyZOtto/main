#pragma once
#include "ozCore.h"

#include <QStringList>

#include <QList>
#include <QMap>
#include <QString>

class OZCORE_EXPORT QQStringList : public QStringList
{
public: // types
    typedef QMap<QString, QString> StringMap;

public: // ctors
    QQStringList();
    QQStringList(const QList<QString> &other);

public: // const
    StringMap map() const;

public: // static
    static QString value(const StringMap &map, const QString &key);
};
