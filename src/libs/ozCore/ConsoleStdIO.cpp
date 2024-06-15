#include "ConsoleStdIO.h"

ConsoleStdIO::ConsoleStdIO(QObject *parent)
    : QObject{parent}
{
    setObjectName("StdIO");
}

void ConsoleStdIO::writeline(const QString &s)
{
    Q_ASSERT(printf("%s\n", qPrintable(s)));
    emit written(stdout, s);
}

void ConsoleStdIO::writelines(const QStringList &sl, const QString prefix)
{
    foreach (QString s, sl)
    {
        s.prepend(prefix);
        writeline(s);
    }
}

void ConsoleStdIO::errorline(const QString &s)
{
    Q_ASSERT(fprintf(stderr, "%s\n", qPrintable(s)));
    emit written(stderr, s);
}
