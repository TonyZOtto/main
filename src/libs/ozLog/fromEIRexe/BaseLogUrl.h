#pragma once

#include <QUrl>

#include <QIODevice>
#include <QString>
#include <QUrlQuery>

#include "../eIRbase/AText.h"
#include "LogObject.h"

class BaseLogUrl : public QUrl
{
public:

public: // ctors
    BaseLogUrl(const Log::UrlType aUrlType=Log::$nullUrlType);
protected:
    BaseLogUrl(const Log::UrlType aUrlType, const QString &aUrlString);
    BaseLogUrl(const Log::UrlType aUrlType, const QUrl &aUrl);

public:
    virtual Log::UrlType type() const = 0;

public:
    void set(const Log::UrlType aUrlType);
    void set(const QString &aUrlString);
    void set(const QUrl &aUrl);

protected:
    bool hasQuery(const QString &aQueryKey) const;
    QString queryValue(const QString &aQueryKey) const;
    QIODevice::OpenMode openMode() const;

private:
    void parseOpenMode();

private:
    Log::UrlType mUrlType=Log::$nullUrlType;
    QUrlQuery mQuery;
    QIODevice::OpenMode mOpenMode=QIODevice::NotOpen;
};

inline QIODeviceBase::OpenMode BaseLogUrl::openMode() const { return mOpenMode; }
