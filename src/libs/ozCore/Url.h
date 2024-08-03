#pragma once
#include "ozCore.h"

#include <QUrl>

class OZCORE_EXPORT Url : public QUrl
{
public: // types
    enum Scheme
    {
        $null = 0,
        dir,
        http,
        https,
        ftp,
    };

public: // ctors
    Url();
    Url(const QUrl &other);
    Url(const QString &s);

public: // const
    Scheme scheme() const;

public: // non-const
    void set(const QUrl &u);
    void set(const QString &s);

public: // static
    static Scheme parseScheme(const QString &s);

private:
    Scheme mScheme=$null;
};

inline Url::Scheme Url::scheme() const { return mScheme; }
