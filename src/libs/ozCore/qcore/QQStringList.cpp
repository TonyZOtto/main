#include "QQStringList.h"

#include "Types.h"

QQStringList::QQStringList() {;}
QQStringList::QQStringList(const QList<QString> &other) : QStringList(other) {;}

QQStringList::StringMap QQStringList::map() const
{
    StringMap result;
    foreach (QString s, *this)
    {
        Index ix = s.indexOf('=');
        QString tKey, tValue;
        if (ix < 0)
            tKey = s;
        else if (ix == 0)
            tValue = s.mid(1);
        else
            tKey = s.left(ix), tValue = s.mid(ix+1);
        result.insert(tKey.toUpper(), tValue);
    }
    return result;
}

QString QQStringList::value(const StringMap &map, const QString &key)
{
    QString result;
    if (map.contains(key.toUpper()))
        result = map[key.toUpper()];
    return result;
}
