#include "Ident.h"

Ident::Ident() : p_id(0) {;}
Ident::Ident(const Key k, const Id i, const QString d)
    : p_uid(Uid(true)), p_key(k), p_id(i ? i : qHash(k)), p_desc(d) {;}
Ident::Ident(const Uid u, const Key k, const Id i, const QString d)
    : p_uid(u), p_key(k), p_id(i ? i : qHash(k)), p_desc(d) {;}

bool Ident::isNull() const
{
    return uid().isNull();
}

QStringList Ident::toDebugStrings() const
{
    QStringList result;
    result << QString("%1 #%2 0x%3 %4").arg(key()())
        .arg(id()).arg(id(), 16, 16, QChar('0')).arg(uid().tail());
    result << desc();
    return result;
}
