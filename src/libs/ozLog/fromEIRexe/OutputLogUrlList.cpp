#include "OutputLogUrlList.h"

#include <QStringList>

OutputLogUrlList::OutputLogUrlList(const QString &aString)
{
    const QStringList cStringList = aString.split(hinge());
    foreach (const QString cUrlString, cStringList)
    {
        const QUrl cUrl(cUrlString);
        const OutputLogUrl cLogUrl(cUrl);
        append(cLogUrl);
    }
}

// static
QChar OutputLogUrlList::smHinge(';');
