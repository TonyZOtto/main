#include "QQDir.h"


QQDir::QQDir(const QString &path)
    : QDir(path)
    , mNull(true) {;}

QQDir::QQDir(const QDir &other)
    : QDir(other)
    , mNull(QDir() == other) {;}

bool QQDir::isNull() const
{
    return mNull.isNull();
}

bool QQDir::notExists() const
{
    return ! exists();
}

QDir QQDir::toQDir() const
{
    return (QDir)(*this);
}

void QQDir::nullify()
{
    (*this) = QDir();
    mNull.nullify();
}
