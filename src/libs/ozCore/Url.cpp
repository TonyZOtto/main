#include "Url.h"

Url::Url() {;}
Url::Url(const QUrl &other)  { set(other); }
Url::Url(const QString &s) { set(s); }

void Url::set(const QUrl &u)
{
    mScheme = parseScheme(u.scheme());
}

void Url::set(const QString &s)
{
    set(QUrl(s));
}

Url::Scheme Url::parseScheme(const QString &s)
{
    Url::Scheme result = $null;
    if (false)
        ;
    else if (s.compare("dir", Qt::CaseInsensitive))
        result = dir;
    else if (s.compare("http", Qt::CaseInsensitive))
        result = http;
    else if (s.compare("https", Qt::CaseInsensitive))
        result = https;
    else if (s.compare("ftp", Qt::CaseInsensitive))
        result = ftp;
    else
        ;
    return result;
}

