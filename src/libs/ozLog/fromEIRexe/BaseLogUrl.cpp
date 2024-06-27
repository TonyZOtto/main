#include "BaseLogUrl.h"

#include <QStringList>

#include "../eIRcore/IODevice.h"

#include "LogObject.h"

BaseLogUrl::BaseLogUrl(const Log::UrlType aUrlType)
{
    set(aUrlType);
}

BaseLogUrl::BaseLogUrl(const Log::UrlType aUrlType, const QString &aUrlString)
{
    set(aUrlType), set(aUrlString);
}

BaseLogUrl::BaseLogUrl(const Log::UrlType aUrlType, const QUrl &aUrl)
{
    set(aUrlType), set(aUrl);
}

void BaseLogUrl::set(const Log::UrlType aUrlType)
{
    mUrlType = aUrlType;
}

void BaseLogUrl::set(const QString &aUrlString)
{
    QUrl::setUrl(aUrlString);
    mQuery = QUrlQuery(*this);
    parseOpenMode();
}

void BaseLogUrl::set(const QUrl &aUrl)
{
    set(aUrl.toString());
}

bool BaseLogUrl::hasQuery(const QString &aQueryKey) const
{
    return mQuery.hasQueryItem(aQueryKey);
}

QString BaseLogUrl::queryValue(const QString &aQueryKey) const
{
    return mQuery.queryItemValue(aQueryKey);
}

void BaseLogUrl::parseOpenMode()
{
    mOpenMode = QIODevice::NotOpen;
    if (hasQuery("OpenMode"))
    {
        const QStringList tOMValues = queryValue("OpenMode").split("+");
        mOpenMode = IODevice::openMode(tOMValues);
    }
}


