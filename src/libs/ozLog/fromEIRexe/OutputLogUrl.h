#pragma once
#include "eIRexe.h"

#include <QList>
#include <QMetaEnum>

class ObjectHelper;

#include "BaseLogUrl.h"

class EIREXE_EXPORT OutputLogUrl : public BaseLogUrl
{
public:
    typedef QList<OutputLogUrl> List;

public: // ctors
    OutputLogUrl();
    OutputLogUrl(const QString &aUrlString);
    OutputLogUrl(const QUrl &aUrl);

public: // virtual
    virtual Log::UrlType type() const { return Log::OutputUrl; }

public: // const
    Log::LevelFlags levelFlags() const;

private:
    Log::OutputFormat parseOutputFormat();
    Log::LevelFlags parseLevels();
    Log::LevelFlags parseLevelString(const QString &aLevelString);
    Log::LevelFlags parseLevelString(const QString &aFromString, const QString &aToString);


private:
    ObjectHelper * mpLogObjectHelper;
    QMetaEnum mMetaEnum;
    Log::OutputFormat mOutputFormat;
    Log::LevelFlags mLevelFlags;
};

inline Log::LevelFlags OutputLogUrl::levelFlags() const { return mLevelFlags; }
